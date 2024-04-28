# Plan

## Planned features

Planned CLI commands:

- `hydra install`

Parses and executes `./hydra.lua` and installs packages based on the exported Manifest.

- `hydra plan`

Parses and executes `./hydra.lua` and shows what `hydra install` would have done (inspired by `terraform plan`).

- `hydra verify`

Parses and executes `./hydra.lua` and then checks that the exported Manifest is valid.

- `hydra cli`

Parses and executes `./hydra.lua` and then drops you into a CLI where you can write and execute Lua code, having access to the exported Manifest.

- `hydra cache clean`

Deletes the local cache, printing out how much disk space you have reclaimed.

- `hydra search`

Parses and executes `./hydra.lua` and then let's you search for any packages using any configured handlers that supports search.

### Script mode

While the commands will normally look for a file called `./hydra.lua` you can also pass a file as the first argument to the `hydra` cli. If you for example wanted to run `hydra plan` on a file you called `test.lua` you could run `hydra ./test.lua plan`.

This syntax should allow you to easily use `hydra` as a shebang in a script. As an example lets assume you have the following `./test.lua` file:

```lua
#!/bin/env hydra

local main = Manifest();

--[[ more code... ]]
```

If you make this file an executable by running `chmod +x ./test.lua` then in the future you could call upon the script as if it was the `hydra` command. So that `./test.lua plan` would be the same as `hydra ./test.lua plan`.

### Piping inn a script

Perhaps we should also allow you to pipe in a script. Ex:

```bash
cat ./test.lua | hydra plan
```
## Built inn features & plugins

`hydra` should aim to have a small core set of built inn providers, that way you can use those to bootstrap `hydra` itself. Most functionality would however come from its planned support of WebAssembly plugins.

### Planned built inn features

`hydra` should support:

- A http(s) download provider (this can be used to download a file given an URL)

- An md5/sha256 checksum provider (this can be used to check the local cache and update the local lockfile)

- An zip / tar.gz unarchiver provider (this can be used to unarchive zip-files and tar.gz-files)

In addition to these 3 build inn providers there are a few additions that might be useful to be built inn:

- An git (https/ssh) provider (as an alternative to `git submodules`)

- An local filesystem provider that also works with network drives

- An sftp/ftp provider

### WebAssemby plugins

Most functionality should be provided by WASM plugins. The point of `hydra` is to be a plugin based tool that can be configured to work in all kind of scenarios, as well as to combine different plugins in new ways that they originally was not planned for.

The `hydra` project should support a few official plugins. This will both ensure that `hydra` can actually be useful in real life, and let us dogfood our own product.

Suggested official plugins to build:

- `npm` / `pnpm` plugins. Supporting the Node ecosystem

- `maven` plugin. Supporting the Java ecosystem

- `svn` plugin. Allowing you to work with projects hosted over SVN.

- `github releases` plugin. A more advanced version of the http(s) provider, specifically supporting features for using stuff from a projects Github Releases page.

- `apt` / `apk` plugin. Allowing you to get packages that you normally can only download with `apt` / `apk`, this might be useful for supporting the C / C++ ecosystem, since they often put stuff directly on their Linux distro's package manager.

- Other archive formats (ex. `rar`)

- Other checksum algorithms

#### WASM plugins

WASM plugins should provide one or more of the following features:

- Download a package

- Search for packages

- Parsers for other manifest and lockfile formats (an `npm` plugin could parse `package.json` as well as lock file, a `maven` plugin could parse `pom.xml` files)

- Archiving and unarchiving of package formats (this could be another archive format like `rar`, or for a `maven` plugin perhaps `.jar` files)

- Additional checksum algorithms

- Specialized package version handling / resolvers

#### Some interesting use cases

- Can we use `hydra` to manage Vim plugins? How about `zsh` plugins?

- Can `hydra` be used to manage packages for game engines like `Unity` and `Godot`?

- Can `hydra` be used as a basis for new projects needing a package manager, instead of implementing a package manager from scratch each time.

- Can `hydra` be used for the C / C++ ecosystem where packages might be spread to many different places (ex. `apt`/`apk` as well as `.tar.gz` files over http(s))?

- Can `hydra` be used for monorepo tooling in a project mixing many different languages?
