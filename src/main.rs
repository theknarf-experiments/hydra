use clap::{Parser, Subcommand};
use crate::check::check;

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

  }
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
