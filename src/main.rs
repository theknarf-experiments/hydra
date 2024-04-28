use clap::{Parser, Subcommand};
use crate::check::*;

mod check;

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

  },
  Repl {

  }
}

fn main() -> Result<(), &'static str> {
  let args = Cli::parse();

  match args.command {
    Commands::Check {} => {
      check()?
    }
    Commands::Repl {} => {
      repl()?
    }
  }

  Ok(())
}
