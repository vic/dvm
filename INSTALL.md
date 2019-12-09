# Installation

You can download a prebuilt binary from GitHub or build it yourself from the
source.

## Homebrew (recommended for macOS users)

```bash
brew install imbsky/tap/dvm
```

## Download a prebuilt binary from GitHub (recommended)

You can download the prebuilt binary from GitHub with

##### Linux

```bash
curl -sL https://github.com/imbsky/dvm/releases/latest/download/dvm-x86_64-ubuntu-latest.tar.gz -o dvm-x86_64-ubuntu-latest.tar.gz
```

##### macOS

```bash
curl -sL https://github.com/imbsky/dvm/releases/latest/download/dvm-x86_64-macOS-latest.tar.gz -o dvm-x86_64-macOS-latest.tar.gz
```

You can unzip the zip file with

##### Linux

```bash
tar zxf dvm-x86_64-ubuntu-latest.tar.gz
```

##### macOS

```bash
tar zxf dvm-x86_64-macOS-latest.tar.gz
```

You can install dvm with

```bash
sudo install dvm /usr/local/bin/dvm
```

Add the init script to your shell's config file with

```bash
# ~/.bashrc

eval "$(dvm init bash)"
```

```fish
# ~/.config/fish/config.fish

dvm init fish | source
```

## Building from source

### Prerequisites

#### esy

Before we can build dvm, we need to make sure that we have a latest esy. (We are
using the nightly version of esy. We can use it by install `@esy-nightly/esy`.)

### Getting the source

You can clone the source from GitHub with

```bash
git clone https://github.com/imbsky/dvm.git
```

You can complete the setup of your development environment with

```bash
cd dvm
esy
```

You can build dvm with

```bash
esy build
```

You can install dvm with

```bash
cp _esy/default/build/default/src/Dvm.exe ./dvm
sudo install dvm /usr/local/bin/dvm
```
