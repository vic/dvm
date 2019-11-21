# dvm

[![Main workflow](https://github.com/imbsky/dvm/workflows/Main%20workflow/badge.svg)](https://github.com/imbsky/dvm/actions)
[![GitHub package.json version](https://img.shields.io/github/package-json/v/imbsky/dvm?style=flat-square)](https://github.com/imbsky/dvm/blob/master/package.json)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![GitHub](https://img.shields.io/github/license/imbsky/dvm?color=brightgreen&style=flat-square)](https://github.com/imbsky/dvm/blob/master/LICENSE)

Fast and simple Deno runtime version manager built with Native Reason.

## Installation

See the file [INSTALL.md](INSTALL.md) for installation instructions.

## Usage

| Command                 | Description                                     |
| ----------------------- | ----------------------------------------------- |
| dvm install [version]   | Install a specific version of a Deno runtime.   |
| dvm uninstall [version] | Uninstall a specific version of a Deno runtime. |
| dvm use [version]       | Set the Deno runtime version.                   |
| dvm ls                  | List installed versions of a Deno runtime.      |
| dvm ls-remote           | List all remote versions of a Deno runtime.     |
| dvm init [shell name]   | Print the path to a Deno runtime.               |

| Variable          | Default  | Description                                |
| ----------------- | -------- | ------------------------------------------ |
| `DVM_INSTALL_DIR` | `~/.dvm` | You can change the installation directory. |

## Benchmark

### dvm

| Command                                          |  Mean [ms] | Min [ms] | Max [ms] | Relative |
| :----------------------------------------------- | ---------: | -------: | -------: | -------: |
| `deno https://deno.land/std/examples/welcome.ts` | 15.7 ± 0.5 |     13.5 |     16.6 |     1.00 |

### Official installer

##### **This does NOT support version management.**

| Command                                          |  Mean [ms] | Min [ms] | Max [ms] | Relative |
| :----------------------------------------------- | ---------: | -------: | -------: | -------: |
| `deno https://deno.land/std/examples/welcome.ts` | 15.8 ± 0.5 |     14.4 |     17.1 |     1.00 |

### asdf-deno

| Command                                          |     Mean [ms] | Min [ms] | Max [ms] | Relative |
| :----------------------------------------------- | ------------: | -------: | -------: | -------: |
| `deno https://deno.land/std/examples/welcome.ts` | 195.5 ± 170.0 |    137.3 |    679.1 |     1.00 |

## Bug reports and user feedback

Please report bugs using the issue tracker at
<https://github.com/imbsky/dvm/issues>

## License

&copy; Contributors Licensed under the
[Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0).
