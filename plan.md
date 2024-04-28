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

```
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
