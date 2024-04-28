use clap::{Parser, Subcommand};


/// A fictional versioning CLI
#[derive(Debug, Parser)] // requires `derive` feature
#[command(name = "hydra")]
#[command(about = "the swiss army knife of package management", long_about = None)]
struct Cli {
		#[command(subcommand)]
    command: Commands,
}

#[derive(Debug, Subcommand)]
enum Commands {
}

fn main() {
    let _args = Cli::parse();
}
