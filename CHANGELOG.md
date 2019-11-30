# Changelog

## 1.1.0 - Unreleased

### Changed

- Rewritten in OCaml.

- Coloring of console output has been removed.

## [1.0.0](https://github.com/imbsky/dvm/releases/tag/v1.0.0) - 2019-11-22

### Added

- Added the feature to change the installation directory using the
  `DVM_INSTALL_DIR` variable.

### Changed

- Remove some annoying console outputs.

- You can now install without the gunzip.

- Symbolic link is now removed if the version being uninstalled matches the
  version set as the global version.

- Changed the list and list-all commands to ls and ls -remote to avoid module
  name conflicts.

- Use the tags API instead of the release API to speed up the retrieval of a
  list of remote versions.

- Changed primary color of console output from red to cyan.

### Fixed

- Fixed an issue causing an error when attempting to install if the installation
  directory does not exist.

- Fixed an issue causing an error when trying to use a non-exist version.

## [0.1.0](https://github.com/imbsky/dvm/releases/tag/v0.1.0) - 2019-11-20

Initial version.
