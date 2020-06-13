# dvm

[![Main workflow](https://github.com/imbsky/dvm/workflows/Main%20workflow/badge.svg?branch=master)](https://github.com/imbsky/dvm/actions)

## Overview

Fast and simple Deno runtime version manager written in OCaml. Inspired by
[fnm](https://github.com/Schniz/fnm). Many version managers must redetermine
which version to use each time they run. Even if you have not changed the
version. This happens in all runs, and you might experience a certain slowdown
while the version manager is searching for versions because the version manager
must traverse the directories to search for version files. dvm calls a symbolic
link directly to executable in the PATH. The version resolution is out of the
way and is faster. Commands that try to find themselves in the PATH find the
expected location. And you don't need any extra dependencies, you can use it
right away.

## Usage

| Command                 | Description                                       |
| ----------------------- | ------------------------------------------------- |
| dvm gc                  | Purge unused versions of the Deno runtime.        |
| dvm init [shell name]   | Print the path to the Deno runtime.               |
| dvm install [version]   | Install a specific version of the Deno runtime.   |
| dvm latest              | Install the latest version of the Deno runtime.   |
| dvm ls                  | List installed versions of the Deno runtime.      |
| dvm ls-remote           | List all remote versions of the Deno runtime.     |
| dvm uninstall [version] | Uninstall a specific version of the Deno runtime. |
| dvm use [version]       | Set the Deno runtime version.                     |

| Variable          | Default  | Description                                |
| ----------------- | -------- | ------------------------------------------ |
| `DVM_INSTALL_DIR` | `~/.dvm` | You can change the installation directory. |

## Benchmark

### dvm

| Command                                          |  Mean [ms] | Min [ms] | Max [ms] | Relative |
| :----------------------------------------------- | ---------: | -------: | -------: | -------: |
| `deno --version`                                 |  5.1 ± 0.6 |      4.2 |      8.0 |     1.00 |
| `deno https://deno.land/std/examples/welcome.ts` | 15.7 ± 0.5 |     13.5 |     16.6 |     1.00 |

### Official installer

##### **This does NOT support version management.**

| Command                                          |  Mean [ms] | Min [ms] | Max [ms] | Relative |
| :----------------------------------------------- | ---------: | -------: | -------: | -------: |
| `deno --version`                                 |  5.2 ± 0.8 |      4.2 |      8.5 |     1.00 |
| `deno https://deno.land/std/examples/welcome.ts` | 15.8 ± 0.5 |     14.4 |     17.1 |     1.00 |

### asdf-deno

| Command                                          |     Mean [ms] | Min [ms] | Max [ms] | Relative |
| :----------------------------------------------- | ------------: | -------: | -------: | -------: |
| `deno --version`                                 |    93.4 ± 2.9 |     89.8 |    105.7 |     1.00 |
| `deno https://deno.land/std/examples/welcome.ts` | 195.5 ± 170.0 |    137.3 |    679.1 |     1.00 |

## Bug reports and user feedback

Please report bugs using the issue tracker at
<https://github.com/imbsky/dvm/issues>.

## License

Licensed under the
[Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0).
