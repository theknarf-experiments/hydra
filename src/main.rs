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

  let hydra_lua_source = fs::read_to_string(HYDRA_LUA).unwrap();

  let lua = Lua::new();

  lua.sandbox(true).unwrap();
  lua.load(hydra_lua_source).exec().unwrap();


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
