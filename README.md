# dvm

Fast and simple Deno runtime version manager built with Native Reason.

## Current Status

You probably don't want to use this, yet. Currently under development so a lot
of features and supports are missing. (We currently only have list-all and
install commands.) If you want to work on making dvm feature-complete, don't
hesitate to open PR! We're not just looking for professional Reason developers
either, beginners, documentarians, etc, are highly welcome!

## Hacking on the code

### Prerequisites

- esy
- git

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

You can build and test this package with

```console
esy build
esy x dvm.exe
```

## License

Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the
License at

<http://www.apache.org/licenses/LICENSE-2.0>

Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
