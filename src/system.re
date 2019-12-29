// Copyright 2019 BSKY
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

let rec rmrf = path =>
  Sys.is_directory(path)
    ? {
      Sys.readdir(path)
      |> Array.iter(filename => rmrf(Filename.concat(path, filename)));
      Unix.rmdir(path);
    }
    : Sys.remove(path);

let uname = Core.Unix.uname();
let sysname = Core.Unix.Utsname.sysname(uname);
let machine = Core.Unix.Utsname.machine(uname);

let os =
  switch (sysname) {
  | "Darwin" => "osx"
  | "Linux" => "linux"
  | _ => failwith(sysname ++ " not supported")
  };

let arch =
  switch (machine) {
  | "x86_64" => "x64"
  | _ => failwith(machine ++ " not supported")
  };
