# Installation

You can download a prebuilt binary from GitHub or build it yourself from the
source.

## Download a prebuilt binary from GitHub (recommended)

Open the latest successful build from the
[Actions](https://github.com/imbsky/dvm/actions) tab and copy the link for your
operating system from the artifact in the upper right.

You can download the prebuilt binary from GitHub with

```console
curl -sL <download link> -o dvm.zip
```

You can unzip the zip file with

```console
unzip dvm.zip
```

You can install dvm with

```console
cd <dvm-ubuntu-latest or dvm-macOS-latest>
sudo install <downloaded file> /usr/local/bin/dvm
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
