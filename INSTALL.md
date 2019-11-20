# Installation

You can download a prebuilt binary from GitHub or build it yourself from the
source.

## Homebrew (recommended for macOS users)

```console
brew install imbsky/tap/dvm
```

## Download a prebuilt binary from GitHub (recommended)

You can download the prebuilt binary from GitHub with

##### Linux

```console
curl -sL https://github.com/imbsky/dvm/releases/latest/download/dvm-x86_64-ubuntu-latest.tar.gz -o dvm-x86_64-ubuntu-latest.tar.gz
```

##### macOS

```console
curl -sL https://github.com/imbsky/dvm/releases/latest/download/dvm-x86_64-macOS-latest.tar.gz -o dvm-x86_64-macOS-latest.tar.gz
```

You can unzip the zip file with

##### Linux

```console
tar zxf dvm-x86_64-ubuntu-latest.tar.gz
```

##### macOS

```console
tar zxf dvm-x86_64-macOS-latest.tar.gz
```

You can install dvm with

```console
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

Before we can build dvm, we need to make sure that we have a latest esy. (We use
asdf to manage our esy versions. You can get asdf via Git or Homebrew.)

### Getting the source

You can clone the source from GitHub with

```console
git clone https://github.com/imbsky/dvm.git
```

You can complete the setup of your development environment with

```console
cd dvm
esy
```

You can build dvm with

```console
esy build
```

You can install dvm with

```console
bash scripts/copy-static-binary.sh
sudo install dvm /usr/local/bin/dvm
```
