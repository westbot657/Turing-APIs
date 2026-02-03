use std::collections::{HashMap, HashSet};
use std::iter::{Enumerate, Peekable};
use std::{fs, io, process};
use std::io::Write;
use std::path::PathBuf;
use std::slice::Iter;
use clap::Parser;
use convert_case::{Case, Casing};
use regex::{Captures, Regex};
use serde::{Deserialize, Serialize};
use tera::{from_value, to_value, Context, Tera, Value};

#[derive(Debug, Serialize, Deserialize)]
pub struct ApiModel {
    pub name: String,
    pub name_h: String,
    pub classes: Vec<ClassDef>,
    pub functions: Vec<FunctionDef>,
    pub version: String,
    pub semver: Semver,
    pub include_core: bool,
}

#[derive(Debug, Default, Serialize, Deserialize)]
pub struct Semver {
    pub major: u32,
    pub minor: u16,
    pub patch: u16,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ClassDef {
    pub name: String,
    #[serde(rename = "static")]
    pub is_static: bool,
    pub doc: Option<String>,
    pub functions: Vec<FunctionDef>,
    pub methods: Vec<FunctionDef>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct FunctionDef {
    pub name: String,
    pub params: Vec<ParamDef>,
    #[serde(rename = "type")]
    pub returns: String,
    #[serde(rename = "static")]
    pub is_static: bool,
    pub doc: Option<String>,
    pub wasm: String,
    pub class_name: Option<String>,
    /// Whether the wasm return needs to be "unpacked", such as String and Vu32
    pub unpack_return: bool,
    /// Whether the wasm return needs to be dequeued from the f32 queue
    pub dequeue_return: bool,
    /// Whether the wasm returns void, self, or a glam type
    pub skip_return: bool,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ParamDef {
    pub name: String,
    #[serde(rename = "type")]
    pub typ: String,
    pub is_glam_type: bool,
}

impl Semver {
    fn parse_into(&mut self, ver: &str) -> Result<(), String> {
        let ver: [u32; 3] = ver
            .splitn(3, ".")
            .map(|x|
                x
                    .trim()
                    .parse::<u32>()
                    .map_err(|e| format!("{e}"))
            )
            .collect::<Result<Vec<u32>, String>>()?
            .try_into()
            .map_err(|_| String::from("version does nto follow semantic version format"))?;

        self.major = ver[0];
        self.minor = u16::try_from(ver[1]).map_err(|e| format!("minor version number is too large: {e}"))?;
        self.patch = u16::try_from(ver[2]).map_err(|e| format!("patch version number is too large: {e}"))?;

        Ok(())
    }
}

static DEFAULT_TYPES: [&str; 26] = [
    "i8", "i16", "i32", "i64",
    "u8", "u16", "u32", "u64",
    "f32", "f64", "bool",
    "String", "&str",
    "CString", "CStr",
    "op*", "void", "self",
    "Vec2", "Vec3", "Vec4", "Quat", "Mat4",
    "void*",
     "Vu32", "&Vu32",
];

/// Returns true if t is NOT a builtin-type
pub fn is_opaque_maybe(t: &str) -> bool {
    !DEFAULT_TYPES.contains(&t)
}

impl ApiModel {

    pub fn parse_doc(lines: &mut Peekable<Enumerate<Iter<&str>>>) -> Option<String> {
        let mut s = Vec::new();
        loop {
            if let Some((_, line)) = lines.peek() {
                if line.starts_with("-- ") {
                    let comment = lines.next().unwrap().1.strip_prefix("-- ").unwrap();
                    s.push(comment);
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        if s.is_empty() {
            None
        } else {
            Some(s.join("\\n"))
        }
    }

    pub fn parse_params(raw: &str, seen_types: &mut HashSet<String>, used_opaquely: &mut HashSet<String>, invalid: &mut bool, reserved: &HashMap<String, Vec<String>>) -> Result<Vec<ParamDef>, String> {
        let mut params = Vec::new();

        let raw = raw.trim();

        for raw_p in raw.split(",") {
            let raw_p = raw_p.trim();
            if let Some((n, t)) = raw_p.split_once(":") {
                let n = n.trim();
                let t = t.trim();
                if let Some(langs) = reserved.get(n) {
                    eprintln!("Invalid param name '{n}' cannot be used, it is a keyword in language(s): {}", langs.join(", "));
                    *invalid = true;
                }
                if is_opaque_maybe(t) {
                    if let Some(langs) = reserved.get(t) {
                        eprintln!("Invalid param type '{t}' cannot be used, it is a keyword in language(s): {}", langs.join(", "));
                        *invalid = true;
                    }

                    seen_types.insert(t.to_string());
                    used_opaquely.insert(t.to_string());
                }

                params.push(ParamDef {
                    name: n.to_string(),
                    typ: t.to_string(),
                    is_glam_type: matches!(t, "Vec2" | "Vec3" | "Vec4" | "Quat" | "Mat4")
                })

            } else if !raw_p.is_empty() {
                eprintln!("Error parsing params: {raw}\n{raw_p}");
                *invalid = true;
            }
        }

        Ok(params)
    }

    pub fn parse_function(
        capt: Captures,
        lines: &mut Peekable<Enumerate<Iter<&str>>>,
        ln_num: usize,
        classes: &mut Vec<ClassDef>,
        functions: &mut Vec<FunctionDef>,
        invalid: &mut bool,
        reserved: &HashMap<String, Vec<String>>,
        current_class: Option<&String>,
        seen_types: &mut HashSet<String>,
        used_opaquely: &mut HashSet<String>,
    ) -> Option<()> {
        let is_static = capt.name("static").is_some();
        let name = capt.name("name").unwrap().as_str();
        let raw_params = capt.name("params").unwrap().as_str();
        let ret = capt.name("ret").unwrap().as_str();
        let wasm = capt.name("wasm").unwrap().as_str();

        if let Some(langs) = reserved.get(name) {
            eprintln!("Invalid function name '{name}' cannot be used, it is a keyword in language(s): {}", langs.join(", "));
            *invalid = true;
        }
        if let Some(langs) = reserved.get(wasm) {
            eprintln!("Invalid wasm binding name '{wasm}' cannot be used, it is a keyword in language(s): {}", langs.join(", "));
            *invalid = true;
        }

        let params = match Self::parse_params(
            raw_params, seen_types, used_opaquely,
            invalid, reserved,
        ) {
            Ok(p) => p,
            Err(e) => {
                eprintln!("[error]: on line {ln_num}: {e}");
                *invalid = true;
                return None;
            }
        };

        if is_opaque_maybe(ret) {
            if let Some(langs) = reserved.get(ret) {
                eprintln!("Invalid return type '{ret}' cannot be used, it is a keyword in language(s): {}", langs.join(", "));
                *invalid = true;
            }

            seen_types.insert(ret.to_string());
            used_opaquely.insert(ret.to_string());
        }

        let doc = Self::parse_doc(lines);

        let unpack_return = matches!(ret, "String" | "Vu32");
        let dequeue_return = matches!(ret, "Vec2" | "Vec3" | "Vec4" | "Quat" | "Mat4");
        let skip_return = dequeue_return || matches!(ret, "void" | "self");

        if let Some(class_name) = &current_class {
            let class = classes
                .iter_mut()
                .find(|c| &c.name == *class_name)
                .expect("Class should exist");

            let fn_def = FunctionDef {
                name: name.to_string(),
                params,
                returns: ret.to_string(),
                is_static,
                doc,
                wasm: wasm.to_string(),
                class_name: Some(class_name.to_string()),
                unpack_return,
                dequeue_return,
                skip_return,

            };

            if is_static {
                class.functions.push(fn_def);
            } else {
                class.is_static = false;
                class.methods.push(fn_def);
            }

        } else {

            functions.push(FunctionDef {
                name: name.to_string(),
                params,
                returns: ret.to_string(),
                is_static: true,
                doc,
                wasm: wasm.to_string(),
                class_name: None,
                unpack_return,
                dequeue_return,
                skip_return
            })
        }
        Some(())
    }

    pub fn parse(input: &str, reserved: &HashMap<String, Vec<String>>) -> (Self, HashSet<String>) {
        let mut classes: Vec<ClassDef> = Vec::new();
        let mut functions: Vec<FunctionDef> = Vec::new();
        let mut current_class: Option<String> = None;
        let mut invalid = false;
        let mut semver = Semver::default();
        let mut version = "0.0.0".to_string();
        let mut api_name: Option<String> = None;
        let mut include_core = false;
        let mut seen_types = HashSet::new();
        let mut used_opaquely = HashSet::new();

        let toml_header_re = Regex::new(r#"\[(?P<name>\w+)]"#).unwrap();

        let fn_re = Regex::new(
            r#"(?x)\s*
            (?P<static>::)?
            (?P<name>\w+)\s*
            \((?P<params>[^)]*)\)\s*
            ->\s*(?P<ret>\w+)\s*
            :\s*(?P<wasm>\w+)\s*
            "#
        ).unwrap();

        let lines = input
            .lines()
            .map(|l| l.splitn(2, "//").next().unwrap().trim())
            .filter(|l| !l.is_empty())
            .collect::<Vec<&str>>();

        let mut lines = lines
            .iter()
            .enumerate()
            .peekable();

        loop {
            let Some((ln_num, line)) = lines.next() else { break };

            if let Some(ver) = line.strip_prefix("#version ") {
                version = ver.trim().to_string();
                semver.parse_into(&version).unwrap_or_else(|e| {
                    eprintln!("[error]: {e}");
                    invalid = true;
                });
                continue;
            }

            if let Some(name) = line.strip_prefix("#api ") {
                api_name = Some(name.trim().replace("-", "_").replace(" ", "_"));
                continue;
            }

            if line.starts_with("#include-core") {
                include_core = true;
                continue;
            };

            if let Some(capt) = toml_header_re.captures(line) {
                let class_name = capt.name("name").unwrap().as_str();
                if class_name == "Global" {
                    current_class = None;
                } else if let Some(langs) = reserved.get(class_name) {
                    eprintln!("Invalid class name '{class_name}' cannot be used, it is a keyword in language(s): {}", langs.join(", "));
                    invalid = true;
                } else {
                    if !classes.iter().any(|c| c.name == class_name) {
                        let doc = Self::parse_doc(&mut lines);

                        classes.push(ClassDef {
                            name: class_name.to_string(),
                            is_static: true,
                            doc,
                            functions: Vec::new(),
                            methods: Vec::new(),
                        });
                    }
                    seen_types.insert(class_name.to_string());
                    current_class = Some(class_name.to_string());

                }
                continue;
            }

            if let Some(capt) = fn_re.captures(line) {
                if let None = Self::parse_function(
                    capt,
                    &mut lines,
                    ln_num,
                    &mut classes,
                    &mut functions,
                    &mut invalid,
                    reserved,
                    current_class.as_ref(),
                    &mut seen_types,
                    &mut used_opaquely,
                ) { continue; }
            }

        }

        for opaque in used_opaquely {
            if let Some(cls) = classes.iter_mut().find(|c| c.name == opaque) {
                cls.is_static = false;
            } else {
                println!("\x1b[38;2;200;200;20m[warning]: type '{opaque}' is used but not defined, a blank stub class will be generated.\x1b[0m");
                classes.push(ClassDef {
                    name: opaque,
                    is_static: false,
                    doc: None,
                    functions: Vec::new(),
                    methods: Vec::new(),
                })
            }
        }


        let Some(name) = api_name else {
            eprintln!("[error]: api file did not specify a name");
            eprintln!("API generation failed due to previous errors.");
            process::exit(1);
        };

        if invalid {
            eprintln!("API generation failed due to previous errors.");
            process::exit(1);
        }

        let name_h = name.replace("_", "-");

        (Self {
            name, name_h,
            classes, functions,
            version, semver,
            include_core,
        }, seen_types)
    }
}


pub fn parse_type_map(passthrough: &Vec<String>) -> Value {
    let mut tm: HashMap<String, HashMap<String, String>> = HashMap::new();

    let table = fs::read_to_string("./api-spec/type-map")
        .expect("Failed to read type-map file");

    let mut lines = table.lines().peekable();

    while let Some(line) = lines.next() {
        let line = line.trim();

        if !line.starts_with('|') {
            continue;
        }

        let mut columns: Vec<&str> = line
            .split('|')
            .map(str::trim)
            .filter(|s| !s.is_empty())
            .collect();

        if columns.len() < 2 || columns[0] != "Type" {
            continue;
        }

        columns.remove(0);

        let current_names: Vec<String> =
            columns.iter().map(|c| c.to_string()).collect();

        for lang in &current_names {
            tm.entry(lang.clone()).or_default();
        }

        if let Some(sep) = lines.peek() {
            if sep.trim().starts_with('|') {
                lines.next();
            }
        }

        while let Some(row) = lines.peek() {
            let row = row.trim();

            if !row.starts_with('|') {
                break;
            }

            let mut cells: Vec<&str> = row
                .split('|')
                .map(str::trim)
                .filter(|s| !s.is_empty())
                .collect();

            if cells.is_empty() {
                lines.next();
                continue;
            }

            let base_type = cells.remove(0);

            for (lang, typ) in current_names.iter().zip(cells.iter()) {
                tm.get_mut(lang)
                    .unwrap()
                    .insert(base_type.to_string(), typ.to_string());
            }

            lines.next();
        }
    }

    for map in tm.values_mut() {
        for ps in passthrough {
            if !map.contains_key(ps) {
                map.insert(ps.clone(), ps.clone());
            }
        }
    }

    to_value(tm).expect("Hashmap failed to convert to serde Value")
}

fn load_reserved_word_map() -> HashMap<String, Vec<String>> {

    let s2 = fs::read_to_string("./api-spec/disallowed").expect("Failed to open disallowed words list");
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
        } else if let Some(langs) = &mut words.get_mut(line) {
            langs.push(current_lang.to_string());
        } else {
            words.insert(line.to_string(), vec![current_lang.to_string()]);
        }
    }

    words
}

fn copy_non_template_files(
    base: &std::path::Path,
    current: &std::path::Path,
    dst_root: &std::path::Path,
    api_name: &str,
) -> io::Result<()> {
    for entry in fs::read_dir(current)? {
        let entry = entry?;
        let path = entry.path();
        if path.is_dir() {
            copy_non_template_files(base, &path, dst_root, api_name)?;
            continue;
        }

        if !path.is_file() {
            continue;
        }

        let file_name = path.file_name().unwrap().to_string_lossy();
        if file_name.ends_with(".tera") {
            continue;
        }

        let rel = path.strip_prefix(base).unwrap_or(&path);
        let dest: PathBuf = dst_root.join(rel).to_string_lossy().replace("__api__", &api_name).replace("--api--", &api_name.replace("_", "-")).into();
        if let Some(parent) = dest.parent() {
            fs::create_dir_all(parent)?;
        }
        fs::copy(&path, &dest)?;
    }

    Ok(())
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


pub fn case_filter(value: &Value, args: &HashMap<String, Value>) -> tera::Result<Value> {
    let input: String = from_value(value.clone())?;

    let style = args
        .get("style")
        .and_then(|v| v.as_str())
        .unwrap_or("snake");

    let converted = match style {
        "camel" => input.to_case(Case::Camel),
        "pascal" => input.to_case(Case::Pascal),
        "snake" => input.to_case(Case::Snake),
        "screaming" | "upper_snake" => input.to_case(Case::UpperSnake),
        "lower" => input.to_lowercase(),
        _ => input,
    };

    Ok(to_value(converted)?)
}

pub fn doc_comment(args: &HashMap<String, Value>) -> tera::Result<Value> {
    let doc = args.get("doc").and_then(|v| v.as_str()).ok_or_else(|| "argument 'doc' not found")?;
    let delimiter = args.get("d").and_then(|v| v.as_str()).ok_or_else(|| "argument 'd' (delimiter) not found")?;
    let out = delimiter.to_string() + &doc.replace("\\n", "\n").replace("\n", &format!("\n{}", delimiter));
    Ok(to_value(out)?)
}

pub fn to_ffi_type(value: &Value, args: &HashMap<String, Value>) -> tera::Result<Value> {
    let input: String = from_value(value.clone())?;
    let input = input.as_str();

    let map = args.get("map").unwrap().as_object().unwrap();

    let ffi_ty = match input {
        "Vec2" | "Vec3" | "Vec4" | "Quat" | "Mat4" | "Vu32" | "String" => "u32",
        "&Vu32" => "void*",
        "&str" => "Cstr",
        _ => input,
    };

    Ok(map.get(ffi_ty).unwrap().clone())
}

pub fn needs_allocator(value: &Value, _args: &HashMap<String, Value>) -> tera::Result<Value> {
    let input = value.as_object().unwrap();
    let mut types = Vec::new();
    if let Some(ret_type) = input.get("type") {
        let t = ret_type.as_str().unwrap();
        types.push(t);
    }
    if let Some(params) = input.get("params") {
        let params = params.as_array().unwrap();
        for param in params {
            let param = param.as_object().unwrap();
            let t = param.get("type").unwrap().as_str().unwrap();
            types.push(t);
        }
    }

    let r = types
        .iter()
        .any(|t| matches!(*t, "String" | "&str" | "Vu32"));

    Ok(if r {
        Value::Bool(true)
    } else {
        Value::Null
    })
}

pub fn is_opaque(value: &Value, _args: &HashMap<String, Value>) -> tera::Result<Value> {
    let input = value.as_str().unwrap();
    Ok(if is_opaque_maybe(input) {
        Value::Bool(true)
    } else {
        Value::Null
    })
}

fn main() {
    let args = Args::parse();

    let input = args.input
        .unwrap_or_else(|| get_input("Enter path to API spec file"));
    let output = args.output
        .unwrap_or_else(|| get_input("Enter output directory path for APIs"));

    let s = fs::read_to_string(input).expect("Failed to read input file");

    let reserved = load_reserved_word_map();

    let (api_model, seen_classes) = ApiModel::parse(&s, &reserved);
    let seen_classes = seen_classes.into_iter().collect::<Vec<String>>();

    let type_map = parse_type_map(&seen_classes);

    // println!("API model: {api_model:#?}");

    let mut ctx = Context::new();
    ctx.insert("api", &api_model);
    ctx.insert("types", &type_map);

    let tera = Tera::new("./templates/**/*.tera");
    let mut tera = match tera {
        Ok(t) => t,
        Err(e) => {
            eprintln!("Failed to parse tera template.\n{e}");
            process::exit(1)
        }
    };

    tera.register_filter("case", case_filter);
    tera.register_function("docs", doc_comment);
    tera.register_filter("ffi_type", to_ffi_type);
    tera.register_filter("needs_alloc", needs_allocator);
    tera.register_filter("is_opaque", is_opaque);

    println!("Clearing output directory");
    fs::remove_dir_all(&output).expect("Unable to clear output directory");
    fs::create_dir(&output).expect("Unable to create output directory");

    let templates_dir = PathBuf::from("./templates/");
    let out_dir_path = PathBuf::from(&output);
    if let Err(e) = copy_non_template_files(&templates_dir, &templates_dir, &out_dir_path, &api_model.name) {
        eprintln!("Failed to copy non-template files: {}", e);
        process::exit(1);
    }

    for name in tera.get_template_names() {
        let nm = name
            .replace("__api__", &api_model.name)
            .replace("--api--", &api_model.name.replace("_", "-"))
            .replace(".tera", "")
            .replace("\\", "/")
            .replace("__", "/");
        let file_name = format!("{}/{}", output.display(), nm);

        println!("Generating {} template...", nm);

        let render = tera
            .render(name, &ctx)
            .unwrap_or_else(|e| panic!("Failed to render API model to {}: {:?}", nm, e));

        if let Some(sep) = file_name.rsplit_once("/") {
            fs::create_dir_all(sep.0).unwrap_or_else(|_| panic!("Unable to create directory {}", sep.0));
        }
        fs::write(file_name, render).unwrap_or_else(|_| panic!("Failed to write render of {} to output", nm))
    }

}
