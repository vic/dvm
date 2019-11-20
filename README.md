# dvm

[![Main workflow](https://github.com/imbsky/dvm/workflows/Main%20workflow/badge.svg)](https://github.com/imbsky/dvm/actions)
[![GitHub package.json version](https://img.shields.io/github/package-json/v/imbsky/dvm?style=flat-square)](https://github.com/imbsky/dvm/blob/master/package.json)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![GitHub](https://img.shields.io/github/license/imbsky/dvm?color=brightgreen&style=flat-square)](https://github.com/imbsky/dvm/blob/master/LICENSE)

Fast and simple Deno runtime version manager built with Native Reason.

## Installation

See the file [INSTALL.md](INSTALL.md) for installation instructions.

## Usage

| Command                 | Effect                                          |
| ----------------------- | ----------------------------------------------- |
| dvm install [version]   | Install a specific version of a Deno runtime.   |
| dvm uninstall [version] | Uninstall a specific version of a Deno runtime. |
| dvm use [version]       | Set the Deno runtime version.                   |
| dvm list                | List installed versions of a Deno runtime.      |
| dvm list-all            | List all versions of a Deno runtime.            |
| dvm init [shell name]   | Print the path to a Deno runtime.               |

| Path              | Effect                                                         |
| ----------------- | -------------------------------------------------------------- |
| `DVM_INSTALL_DIR` | You can change the installation directory. (Default: `~/.dvm`) |

## Bug reports and user feedback

Please report bugs using the issue tracker at
<https://github.com/imbsky/dvm/issues>

## License

&copy; Contributors Licensed under the
[Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0).
