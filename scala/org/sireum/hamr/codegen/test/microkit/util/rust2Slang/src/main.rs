#![allow(non_snake_case)]

use std::env;
use std::fs::File;
use std::io::{self, Read, Write};
use serde::ser::{Serialize, Serializer, SerializeStruct};
use serde_json;
use syn::{Expr, parse_str};
use quote::quote;

#[derive(Debug)]
pub enum SimpleExpr {
    Binary {
        left: Box<SimpleExpr>,
        op: String,
        right: Box<SimpleExpr>,
    },
    Unary {
        op: String,
        expr: Box<SimpleExpr>,
    },
    Ident(String),
    LitB(String),
    LitZ(String),
    Invoke {
        name: String,
        args: Vec<SimpleExpr>,
    },
    Unknown,
}

impl Serialize for SimpleExpr {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: Serializer,
    {
        match self {
            SimpleExpr::Binary { op, left, right } => {
                let mut s = serializer.serialize_struct("Binary", 3)?;
                s.serialize_field("type", "Binary")?;
                s.serialize_field("left", left)?;
                s.serialize_field("op", op)?;
                s.serialize_field("right", right)?;
                s.end()
            }
            SimpleExpr::Unary { op, expr } => {
                let mut s = serializer.serialize_struct("Unary", 2)?;
                s.serialize_field("type", "Unary")?;
                s.serialize_field("op", op)?;
                s.serialize_field("expr", expr)?;
                s.end()
            }
            SimpleExpr::Ident(id) => {
                let mut s = serializer.serialize_struct("Ident", 1)?;
                s.serialize_field("type", "Ident")?;
                s.serialize_field("value", id)?;
                s.end()
            }
            SimpleExpr::LitZ(id) => {
                let mut s = serializer.serialize_struct("LitZ", 1)?;
                s.serialize_field("type", "LitZ")?;
                s.serialize_field("value", id)?;
                s.end()
            }
            SimpleExpr::LitB(id) => {
                let mut s = serializer.serialize_struct("LitB", 1)?;
                s.serialize_field("type", "LitB")?;
                s.serialize_field("value", id)?;
                s.end()
            }
            SimpleExpr::Invoke { name, args } => {
                let mut s = serializer.serialize_struct("Invoke", 2)?;
                s.serialize_field("type", "Invoke")?;
                s.serialize_field("name", name)?;
                s.serialize_field("args", args)?;
                s.end()
            }
            SimpleExpr::Unknown => {
                let mut s = serializer.serialize_struct("Unknown", 1)?;
                s.serialize_field("type", "Unknown")?;
                s.end()
            }
        }
    }
}

// Function to parse the expression from the file
fn parse_expression_from_file(file_path: &str) -> io::Result<String> {
    let mut file = File::open(file_path)?;
    let mut content = String::new();
    file.read_to_string(&mut content)?;
    Ok(content)
}

// Write the serialized JSON to an output file
fn write_json_to_file(json: &str, output_path: &str) -> io::Result<()> {
    let mut file = File::create(output_path)?;
    file.write_all(json.as_bytes())?;
    Ok(())
}

fn is_ascii_number(s: &str) -> bool {
        !s.is_empty() && s.chars().all(|c| c.is_ascii_digit())
}

fn convert_to_ast(expression: &str) -> SimpleExpr {
    match parse_str::<Expr>(expression) {
        Ok(syn_expr) => match syn_expr {
            Expr::Binary(bin) => {
                let op = bin.op;
                let lhs = bin.left;
                let rhs = bin.right;

                SimpleExpr::Binary {
                    left: Box::new(convert_to_ast(&quote! { #lhs }.to_string())),
                    op: quote! { #op }.to_string(),
                    right: Box::new(convert_to_ast(&quote! { #rhs }.to_string())),
                }
            },
            Expr::Unary(un) => {
                let op = un.op;
                let expr = un.expr;

                SimpleExpr::Unary {
                  op: quote! { #op }.to_string(),
                  expr: Box::new(convert_to_ast(&quote! { #expr }.to_string())),
                }
            },
            Expr::Path(path) => {
                if let Some(segment) = path.path.segments.first() {
                    let x = segment.ident.to_string();
                    match x.as_str() {
                        "T" | "F" => SimpleExpr::LitB(x),
                        z if is_ascii_number(z) => SimpleExpr::LitZ(x),
                        _ => SimpleExpr::Ident(x),
                    }
                } else {
                    SimpleExpr::Unknown
                }
            },
            Expr::Lit(lit) => {
                match quote! { #lit }.to_string() {
                    x if is_ascii_number(&x) => SimpleExpr::LitZ(x),
                    _ => panic!()
                }
            },
            Expr::Paren(paren) => {
              let expr = paren.expr;
              //SimpleExpr::Paren(Box::new(convert_to_ast(&quote! { #expr }.to_string())))
              convert_to_ast(&quote! { #expr }.to_string())
            },
            Expr::Call(call) => {
                let funcName = call.func;
                //let func = convert_to_ast(&quote! { #funcName }.to_string());
                let args = call
                    .args
                    .into_iter()
                    .map(|arg| convert_to_ast(&quote! { #arg }.to_string()))
                    .collect();
                SimpleExpr::Invoke {
                    name: quote! { #funcName }.to_string(),
                    args: args }
            },
            _ => SimpleExpr::Unknown,
        },
        Err(_) => SimpleExpr::Unknown,
    }
}


fn main() {
    // Parse CLI arguments
    let args: Vec<String> = env::args().collect();
    if args.len() != 3 {
        eprintln!("Usage: {} <input_file> <output_file>", args[0]);
        return;
    }

    let input_file = &args[1];
    let output_file = &args[2];

    // Read expressions from input file
    let expression_content = match parse_expression_from_file(input_file) {
        Ok(content) => content,
        Err(e) => {
            eprintln!("Failed to read input file: {}", e);
            return;
        }
    };

    // Convert the expression to an AST
    let ast = convert_to_ast(&expression_content);

    // Serialize AST to JSON
    let json_output = match serde_json::to_string_pretty(&ast) {
        Ok(json) => json,
        Err(e) => {
            eprintln!("Failed to serialize AST: {}", e);
            return;
        }
    };

    println!("{}", json_output);

    // Write JSON to output file
    if let Err(e) = write_json_to_file(&json_output, output_file) {
        eprintln!("Failed to write to output file: {}", e);
    } else {
        println!("AST successfully written to {}", output_file);
    }
}
