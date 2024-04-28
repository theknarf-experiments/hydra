use clap::{Parser, Subcommand};
use std::path::Path;
use std::fs;
use mlua::prelude::*;

#[derive(Debug, Parser)]
#[command(name = "hydra")]
#[command(about = "the swiss army knife of package management", long_about = None)]
struct Cli {
  #[command(subcommand)]
  command: Commands,
}

#[derive(Debug, Subcommand)]
enum Commands {
  Check {

  }
}

fn check() -> Result<(), &'static str> {
  const HYDRA_LUA : &str = "./hydra.lua";

  if !Path::new(HYDRA_LUA).exists() {
    return Result::Err("Missing lua");
  }

  let source = fs::read_to_string(HYDRA_LUA).unwrap();

  let lua = Lua::new();
  lua.sandbox(true).unwrap();

  let globals = lua.globals();

  // A handler is a set of plugins for handeling packages
  let handler = lua.create_function(|lua, ()| {
    let t = lua.create_table()?;

    let add_handler = lua.create_function(|_,()| {
      print!("TODO: implement add_handler\n");
      Ok(())
    })?;
    t.set("add_handler", add_handler)?;

    Ok(t)
  }).unwrap();
  globals.set("Handler", handler).unwrap();

  // A Manifest is our data object
  // with it you can add dependencies
  let manifest = lua.create_function(|lua, ()| {
    let t = lua.create_table()?;

    let add_dependency = lua.create_function(|_,()| {
      print!("todo: implement add_dependency\n");
      Ok(())
    })?;
    t.set("add_dependency", add_dependency)?;

    Ok(t)
  }).unwrap();
  globals.set("Manifest", manifest).unwrap();

  lua.load(source).exec().unwrap();

  Ok(())
}

fn main() -> Result<(), &'static str> {
  let args = Cli::parse();

  match args.command {
    Commands::Check {} => {
      check()?
    }
  }

  Ok(())
}
