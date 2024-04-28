use std::path::Path;
use std::fs;
use mlua::prelude::*;
use mlua::{MetaMethod, UserData};

/// A handler is a set of plugins for handeling packages
#[derive(Default)]
pub struct Handler;

impl UserData for Handler {
    fn add_fields<'lua, F: mlua::UserDataFields<'lua, Self>>(_fields: &mut F) {
    }
    fn add_methods<'lua, M: mlua::UserDataMethods<'lua, Self>>(methods: &mut M) {
      methods.add_method("add_handler", |_, _this, ()| {
        print!("TODO: implement add_handler\n");
        Ok(())
      });

      // Constructor
      methods.add_meta_function(MetaMethod::Call, |_, ()| Ok(Handler::default()));
    }
}

/// A Manifest is our data object
/// with it you can add dependencies
#[derive(Default)]
pub struct Manifest;

impl UserData for Manifest {
    fn add_fields<'lua, F: mlua::UserDataFields<'lua, Self>>(_fields: &mut F) {
    }
    fn add_methods<'lua, M: mlua::UserDataMethods<'lua, Self>>(methods: &mut M) {
      methods.add_method("add_dependency", |_, _this, ()| {
        print!("todo: implement add_dependency\n");
        Ok(())
      });

      // Constructor
      methods.add_meta_function(MetaMethod::Call, |_, ()| Ok(Manifest::default()));
    }
}

#[derive(Default)]
struct Dependency;

impl UserData for Dependency {
    fn add_fields<'lua, F: mlua::UserDataFields<'lua, Self>>(_fields: &mut F) {
    }
    fn add_methods<'lua, M: mlua::UserDataMethods<'lua, Self>>(methods: &mut M) {
      // Constructor
      methods.add_meta_function(MetaMethod::Call, |_, ()| Ok(Dependency::default()));
    }
}


pub fn check() -> Result<(), &'static str> {
  const HYDRA_LUA : &str = "./hydra.lua";

  if !Path::new(HYDRA_LUA).exists() {
    return Result::Err("Missing lua");
  }

  let source = fs::read_to_string(HYDRA_LUA).unwrap();

  let lua = Lua::new();
  lua.sandbox(true).unwrap();

  lua.globals().set("Handler", Handler).unwrap();
  lua.globals().set("Manifest", Manifest).unwrap();
  lua.globals().set("Dependency", Dependency).unwrap();

  lua.load(source).exec().unwrap();

  Ok(())
}