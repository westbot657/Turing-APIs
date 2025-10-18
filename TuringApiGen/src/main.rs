use clap::Parser;
use convert_case::{Case, Casing};
use indexmap::IndexMap;
use serde::{Deserialize, Serialize};
use std::collections::{HashMap, VecDeque};
use std::fs;
use std::io::{self, Write};
use std::path::PathBuf;
use tera::{from_value, to_value, Context, Tera, Value, Result as TeraResult};

use regex::Regex;

#[derive(Debug, Serialize, Deserialize)]
pub struct ApiModel {
    pub classes: Vec<ClassDef>,
    pub functions: Vec<FunctionDef>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ClassDef {
    pub name: String,
    pub variables: Vec<VarDef>,
    pub methods: Vec<FunctionDef>,
    pub functions: Vec<FunctionDef>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct VarDef {
    pub name: String,
    #[serde(rename = "type")]
    pub typ: String,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct FunctionDef {
    pub name: String,
    pub returns: String,
    pub params: Vec<ParamDef>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub from: Option<String>,
    #[serde(default)]
    pub is_static: bool,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ParamDef {
    pub name: String,
    #[serde(rename = "type")]
    pub typ: String,
}

pub fn parse_api(input: &str) -> ApiModel {
    let mut classes: Vec<ClassDef> = Vec::new();
    let mut functions: Vec<FunctionDef> = Vec::new();
    let mut current_class: Option<String> = None;

    let func_re = Regex::new(
        r#"(?x)
        (?P<prefix>::)?             # optional '::' for class functions
        (?P<ret>\w+)\s+             # return type
        (?P<name>\w+)               # function name
        \s*\((?P<params>[^)]*)\)    # params
        (?:\s+from\s+(?P<from>\S+))? # optional 'from' source
        "#
    ).unwrap();

    for line in input.lines().map(|l| l.trim()) {
        if line.is_empty() {
            continue;
        }

        // Section header like ":My_Class:"
        if line.starts_with(':') && line.ends_with(':') {
            let name = line.trim_matches(':').to_string();
            if name == "Global" {
                current_class = None;
            } else {
                // Ensure the class exists in our vector
                if !classes.iter().any(|c| c.name == name) {
                    classes.push(ClassDef {
                        name: name.clone(),
                        variables: Vec::new(),
                        methods: Vec::new(),
                        functions: Vec::new(),
                    });
                }
                current_class = Some(name);
            }
            continue;
        }

        // Function definition line
        if let Some(caps) = func_re.captures(line) {
            let is_static = caps.name("prefix").is_some();
            let returns = caps["ret"].to_string();
            let name = caps["name"].to_string();
            let from = caps.name("from").map(|m| m.as_str().to_string());

            // Parse params
            let mut params = Vec::new();
            let params_text = caps["params"].trim();
            if !params_text.is_empty() {
                for param in params_text.split(',') {
                    let param = param.trim();
                    if let Some((n, t)) = param.split_once(':') {
                        params.push(ParamDef {
                            name: n.trim().to_string(),
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
        }
    }

    ApiModel { classes, functions }
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

fn main() {
    let args = Args::parse();

    let input = args.input.unwrap_or_else(|| get_input("Enter path to API spec file"));
    let output = args.output.unwrap_or_else(|| get_input("Enter output folder for API bindings"));

    let s = fs::read(input).expect("Failed to read input file");
    let s = String::from_utf8(s).expect("input contained invalid UTF-8");
    let api_model = parse_api(&s);
    let type_map = parse_typemap();

    println!("API model: {:#?}\n\nType map: {:#?}", api_model, type_map);


    let mut ctx = Context::new();
    ctx.insert("api", &api_model);
    ctx.insert("types", &type_map);

    let mut tera = Tera::new("./templates/*.tera").unwrap();

    tera.register_filter("case", case_filter);

    for name in tera.get_template_names() {
        let extension = name.replace(".tera", "");
        let file_name = format!("{}/api.{}", output.display(), extension);

        println!("will try to save to {}", file_name);

        let render = tera.render(name, &ctx).expect(&format!("Failed to render API model to {}", extension));

        fs::write(file_name, render).expect(&format!("Failed to write render of {} to output", extension))

    }

}
