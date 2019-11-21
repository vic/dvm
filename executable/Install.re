/*
 Copyright 2019 BSKY
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

open Dvm;

let createDownloadUrl = version =>
  "https://github.com/denoland/deno/releases/download/v"
  ++ version
  ++ "/deno_"
  ++ System.os
  ++ "_"
  ++ System.arch
  ++ ".gz";

let run = version => {
  let downloadUrl = createDownloadUrl(version);
  let installVersionDir = Filename.concat(Constant.installDir, version);
  let binaryPath = Filename.concat(installVersionDir, "deno");

  if (!Sys.file_exists(Constant.dvmDir)) {
    Core.Unix.mkdir_p(Constant.dvmDir);
  };

  if (Sys.file_exists(installVersionDir)) {
    Console.log(
      <Pastel>
        "Deno runtime version "
        <Pastel color=Pastel.Red underline=true> version </Pastel>
        " is already installed."
      </Pastel>,
    );
    exit(1);
  };

  Core.Unix.mkdir_p(installVersionDir);
  Core_kernel.Out_channel.write_all(
    binaryPath,
    ~data=Rresult.R.get_ok(Http.Curl.get(downloadUrl) |> Ezgzip.decompress),
  );

  Core.Unix.chmod(binaryPath, ~perm=755);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Cyan underline=true> version </Pastel>
      " was successfully installed!"
    </Pastel>,
  );
};
