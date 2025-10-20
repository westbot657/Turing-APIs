use clap::Parser;
use convert_case::{Case, Casing};
use indexmap::IndexMap;
use serde::{Deserialize, Serialize};
use std::collections::{HashMap, VecDeque};
use std::fs;
use std::io::{self, Write};
use std::path::PathBuf;
use std::process::exit;
use tera::{from_value, to_value, Context, Tera, Value, Result as TeraResult};

use regex::Regex;

#[derive(Debug, Serialize, Deserialize)]
pub struct ApiModel {
    pub classes: Vec<ClassDef>,
    pub functions: Vec<FunctionDef>,
    pub opaque_classes: Vec<String>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ClassDef {
    pub name: String,
    pub variables: Vec<VariableDef>,
    pub methods: Vec<FunctionDef>,
    pub functions: Vec<FunctionDef>,
    pub is_opaque: bool,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct VariableDef {
    pub name: String,
    #[serde(rename = "type")]
    pub typ: String,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct FunctionDef {
    pub name: String,
    pub params: Vec<ParamDef>,
    #[serde(rename = "type")]
    pub returns: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub from: Option<String>,
    pub is_static: bool,

    // new field
    #[serde(default)]
    pub returns_opaque: bool,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ParamDef {
    pub name: String,
    #[serde(rename = "type")]
    pub typ: String,
}

pub fn parse_api(input: &str, reserved: &HashMap<String, Vec<String>>) -> ApiModel {
    let mut classes: Vec<ClassDef> = Vec::new();
    let mut functions: Vec<FunctionDef> = Vec::new();
    let mut current_class: Option<String> = None;
    let mut invalid_name = false;

    let func_re = Regex::new(
        r#"(?x)
        (?P<prefix>::)?             # optional '::' for static
        (?P<name>\w+)\s*            # function name
        \((?P<params>[^)]*)\)\s*    # parameters
        ->\s*(?P<ret>\w+)           # return type
        (?:\s*:\s*(?P<from>\S+))?   # optional source after colon
        "#
    ).unwrap();

    let var_re = Regex::new(r#"^\.(?P<name>\w+)\s*:\s*(?P<typ>\S+)$"#).unwrap();

    for line in input.lines().map(|l| l.trim()).filter(|l| !l.is_empty()) {
        if line.starts_with("//") { continue }
        // Section header like ":My_Class:"
        if line.starts_with(':') && line.ends_with(':') {
            let header = line.trim_matches(':').trim();
            let (name, is_opaque) = if let Some((name, flags)) = header.split_once(' ') {
                (name.trim().to_string(), flags.contains("[opaque]"))
            } else {
                (header.to_string(), false)
            };

            if name == "Global" {
                current_class = None;
            } else if let Some(langs) = reserved.get(&name) {
                eprintln!("Invalid class name '{}' cannot be used, it is a keyword in language(s): {}", name, langs.join(", "));
                invalid_name = true;
            } else {
                if !classes.iter().any(|c| c.name == name) {
                    let mut vars = Vec::new();
                    if is_opaque {
                        vars.push(VariableDef {
                            name: "opaqu".to_string(),
                            typ: "op*".to_string(),
                        });
                    }
                    classes.push(ClassDef {
                        name: name.clone(),
                        variables: vars,
                        methods: Vec::new(),
                        functions: Vec::new(),
                        is_opaque,
                    });
                }
                current_class = Some(name);
            }
            continue;
        }


        // Variable definition line like ".attr: i32"
        if let Some(caps) = var_re.captures(line) {

            let name = caps["name"].to_string();

            if let Some(langs) = reserved.get(&name) {
                eprintln!("Invalid variable name '{}' cannot be used, it is a keyword in language(s): {}", name, langs.join(", "));
                invalid_name = true;
            }

            let var = VariableDef {
                name,
                typ: caps["typ"].to_string(),
            };
            if let Some(class_name) = &current_class {
                let class = classes
                    .iter_mut()
                    .find(|c| &c.name == class_name)
                    .expect("Class should exist");
                class.variables.push(var);
            } else {
                panic!("Variables are only allowed inside classes");
            }
            continue;
        }

        // Function definition line
        if let Some(caps) = func_re.captures(line) {
            let is_static = caps.name("prefix").is_some();
            let name = caps["name"].to_string();
            let returns = caps["ret"].to_string();
            let mut from = caps.name("from").map(|m| m.as_str().to_string());
            if from.is_none() {
                from = Some(format!("_{}", name));
            }

            if let Some(langs) = reserved.get(&name) {
                eprintln!("Invalid function name '{}' cannot be used, it is a keyword in language(s): {}", name, langs.join(", "));
                invalid_name = true;
            }

            if let Some(ref from) = from {
                if let Some(langs) = reserved.get(from) {
                    eprintln!("Invalid wasm function name '{}' cannot be used, it is a keyword in language(s): {}", from, langs.join(", "));
                    invalid_name = true;
                }
            }

            // Parse parameters
            let mut params = Vec::new();
            let params_text = caps["params"].trim();
            if !params_text.is_empty() {
                for param in params_text.split(',') {
                    let param = param.trim();
                    if let Some((n, t)) = param.split_once(':') {
                        let n = n.trim().to_string();
                        if let Some(langs) = reserved.get(&n) {
                            eprintln!("Invalid param name '{}' cannot be used, it is a keyword in language(s): {}", n, langs.join(", "));
                            invalid_name = true;
                        }

                        params.push(ParamDef {
                            name: n,
                            typ: t.trim().to_string(),
                        });
                    }
                }
            }

            let func = FunctionDef {
                name,
                returns,
                params,
                from,
                is_static,
                returns_opaque: false,
            };

            if let Some(class_name) = &current_class {
                let class = classes
                    .iter_mut()
                    .find(|c| &c.name == class_name)
                    .expect("Class should exist");
                if is_static {
                    class.functions.push(func);
                } else {
                    class.methods.push(func);
                }
            } else {
                functions.push(func);
            }

            continue;
        }

        panic!("Unrecognized line: {}", line);
    }

    if invalid_name {
        eprintln!("Generating API failed due to previous errors.");
        ::std::process::exit(1);
    }

    ApiModel { classes, functions, opaque_classes: Vec::new() }
}


pub fn finalize_opaque_returns(mut api: ApiModel) -> ApiModel {
    // Collect all opaque class names
    let opaque_classes: Vec<String> = api
        .classes
        .iter()
        .filter(|c| c.is_opaque)
        .map(|c| c.name.clone())
        .collect();

    api.opaque_classes = opaque_classes.clone();

    // Helper to mark a function as returning opaque if needed
    let mark_opaque = |func: &mut FunctionDef| {
        if opaque_classes.contains(&func.returns) {
            func.returns_opaque = true;
        }
    };

    // Global functions
    for func in &mut api.functions {
        mark_opaque(func);
    }

    // Class methods and static functions
    for class in &mut api.classes {
        for func in &mut class.methods {
            mark_opaque(func);
        }
        for func in &mut class.functions {
            mark_opaque(func);
        }
    }

    api
}


#[derive(Parser, Debug)]
#[command(name = "turingapigen")]
#[command(about = "Generate APIs from templates", long_about = None)]
struct Args {
    #[arg(short, long)]
    input: Option<PathBuf>,

    #[arg(short, long)]
    output: Option<PathBuf>,
}

fn get_input(label: &str) -> PathBuf {
    print!("{label}: ");
    io::stdout().flush().unwrap();

    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();

    PathBuf::from(buf.trim())
}

pub fn case_filter(value: &Value, args: &HashMap<String, Value>) -> TeraResult<Value> {
    // Extract input string
    let input: String = from_value(value.clone())?;

    // Extract argument `style`, default = "snake"
    let style = args
        .get("style")
        .and_then(|v| v.as_str())
        .unwrap_or("snake");

    // Convert to desired case
    let converted = match style {
        "camel" => input.to_case(Case::Camel),
        "pascal" => input.to_case(Case::Pascal),
        "snake" => input.to_case(Case::Snake),
        "screaming" | "upper_snake" => input.to_case(Case::UpperSnake),
        _ => input, // fallback: unchanged
    };

    Ok(to_value(converted)?)
}

pub fn parse_typemap() -> Value {
    let mut tm = HashMap::new();

    let table = fs::read_to_string("./api-spec/type-map").expect("Failed to read type-map file");

    let mut table: VecDeque<&str> = table.split("\n").collect::<VecDeque<&str>>().into();

    let mut names = Vec::new();

    loop {
        let header = table.pop_front().expect("File ended before table was found").trim();
        if !header.starts_with("|") { continue }

        let mut columns: VecDeque<&str> = header.split("|").map(|x| x.trim()).filter(|x| !x.is_empty()).collect::<VecDeque<&str>>().into();

        let _ = columns.pop_front().expect("Expected something after '|'");

        for col in columns {
            names.push(col.to_string());
            tm.insert(col.to_string(), HashMap::new());
        }
        break;
    }

    let _ = table.pop_front().expect("Expected header separater");

    for line in table {
        if !line.starts_with("|") { continue }

        let mut types: VecDeque<&str> = line.split("|").map(|x| x.trim()).filter(|x| !x.is_empty()).collect::<VecDeque<&str>>().into();

        let base_type = types.pop_front().expect("Expected base type");

        for (typ, lang) in types.iter().zip(&names) {
            tm.get_mut(lang).unwrap().insert(base_type.to_string(), typ.to_string());
        }

    }


    to_value(tm).expect("Hashmap failed to convert to serde Value")
}

fn load_reserved_word_map() -> HashMap<String, Vec<String>> {

    let s2 = fs::read_to_string("./api-spec/dissallowed").expect("Failed to open dissallowed words list");
    let s: Vec<&str> = s2
        .split("\n")
        .map(|l| l.trim())
        .filter(|l| !(l.starts_with("//") || l.is_empty()))
        .collect();

    let mut words: HashMap<String, Vec<String>> = HashMap::new();
    let mut current_lang = "All";

    for line in s {
        if let Some(line) = line.strip_prefix("#") {
            current_lang = line;
        } else {
            if let Some(langs) = &mut words.get_mut(line) {
                langs.push(current_lang.to_string());
            } else {
                words.insert(line.to_string(), vec![current_lang.to_string()]);
            }
        }
    }

    words
}

fn main() {
    let args = Args::parse();

    let input = args.input.unwrap_or_else(|| get_input("Enter path to API spec file"));
    let output = args.output.unwrap_or_else(|| get_input("Enter output folder for API bindings"));

    let s = fs::read(input).expect("Failed to read input file");
    let s = String::from_utf8(s).expect("input contained invalid UTF-8");

    let reserved = load_reserved_word_map();

    let api_model = finalize_opaque_returns(parse_api(&s, &reserved));
    let type_map = parse_typemap();

    println!("API: {:#?}\n\nTypeMap: {:#?}", api_model, type_map);

    let mut ctx = Context::new();
    ctx.insert("api", &api_model);
    ctx.insert("types", &type_map);

    let mut tera = Tera::new("./templates/*.tera").unwrap();

    tera.register_filter("case", case_filter);

    for name in tera.get_template_names() {
        let extension = name.replace(".tera", "");
        let file_name = format!("{}/{}", output.display(), extension);

        println!("Generating {} template...", extension);

        let render = tera.render(name, &ctx).expect(&format!("Failed to render API model to {}", extension));

        fs::write(file_name, render).expect(&format!("Failed to write render of {} to output", extension))

    }

}
