/*
 Copyright 2019-2020 BSKY
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

let containsSubstring = (search, pattern) =>
  Core.String.substr_index(search, ~pattern) != None;

let removeUnusedVersion = (version, isUsed) =>
  if (isUsed) {
    Console.log(
      <Pastel>
        "\n"
        <Pastel color=Pastel.Cyan underline=true> version </Pastel>
        " was not removed because it's the current version."
      </Pastel>,
    );
  } else {
    System.rmrf(Filename.concat(Constant.installDir, version));
    Console.log(
      <Pastel>
        <Pastel color=Pastel.Cyan underline=true> version </Pastel>
        " was successfully purged!"
      </Pastel>,
    );
  };

let run = () =>
  if (Sys.file_exists(Constant.currentSymLinkPath)) {
    Core.Sys.ls_dir(Constant.installDir)
    |> List.rev
    |> List.iter(version =>
         version
         |> containsSubstring(Constant.currentSymLinkPath |> Unix.readlink)
         |> removeUnusedVersion(version)
       );
  } else {
    Console.log("Could not run gc because the current version is not set.");
    exit(1);
  };
