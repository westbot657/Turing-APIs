use clap::Parser;
use convert_case::{Case, Casing};
use serde::{Deserialize, Serialize};
use std::collections::HashMap;
use std::fs;
use std::io::{self, Write};
use std::path::PathBuf;
use tera::{from_value, to_value, Context, Tera, Value, Result as TeraResult};

use regex::Regex;

fn parse_api(input: &str) -> ApiModel {
    let mut classes = HashMap::new();
    let mut functions = HashMap::new();
    let mut current_section = String::from("Global");

    let func_re = Regex::new(
        r#"(?x)
        (?P<ret>\w+)\s+
        (?P<name>\w+)
        \s*\((?P<params>[^)]*)\)
        (?:\s+from\s+(?P<from>\S+))?
        "#
    ).unwrap();

    for line in input.lines().map(|l| l.trim()) {
        if line.is_empty() { continue; }

        // Section header
        if line.starts_with(':') && line.ends_with(':') {
            current_section = line.trim_matches(':').to_string();
            continue;
        }

        // Function definition
        if let Some(caps) = func_re.captures(line) {
            let returns = caps["ret"].to_string();
            let name = caps["name"].to_string();
            let from = caps.name("from").map(|m| m.as_str().to_string());

            // Parse params
            let mut params = HashMap::new();
            let params_text = caps["params"].trim();
            if !params_text.is_empty() {
                for param in params_text.split(',') {
                    let param = param.trim();
                    if let Some((n, t)) = param.split_once(':') {
                        params.insert(n.trim().to_string(), t.trim().to_string());
                    }
                }
            }

            let func = FunctionDef { returns, params, from };

            if current_section == "Global" {
                functions.insert(name, func);
            } else {
                classes
                    .entry(current_section.clone())
                    .or_insert_with(|| ClassDef {
                        variables: HashMap::new(),
                        methods: HashMap::new(),
                        functions: HashMap::new(),
                    })
                    .methods
                    .insert(name, func);
            }
        }
    }

    ApiModel { classes, functions }
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ApiModel {
    pub classes: HashMap<String, ClassDef>,
    pub functions: HashMap<String, FunctionDef>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ClassDef {
    pub variables: HashMap<String, String>,
    pub methods: HashMap<String, FunctionDef>,
    pub functions: HashMap<String, FunctionDef>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct FunctionDef {
    pub returns: String,
    pub params: HashMap<String, String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub from: Option<String>
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

fn main() {
    let args = Args::parse();

    let input = args.input.unwrap_or_else(|| get_input("Enter path to API spec file"));
    let output = args.output.unwrap_or_else(|| get_input("Enter output folder for API bindings"));

    let s = fs::read(input).expect("Failed to read input file");
    let s = String::from_utf8(s).expect("input contained invalid UTF-8");
    let api_model = parse_api(&s);

    let mut ctx = Context::new();
    ctx.insert("api", &api_model);

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
