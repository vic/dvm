/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

let run = version => {
  let installVersionDir = Filename.concat(Constant.installDir, version);
  let binaryPath = Filename.concat(installVersionDir, "deno");

  if (!Sys.file_exists(binaryPath)) {
    Console.log(
      <Pastel>
        "Deno runtime version "
        <Pastel color=Pastel.Cyan underline=true> version </Pastel>
        " does not exist."
      </Pastel>,
    );
    exit(1);
  };

  if (!Sys.file_exists(Constant.currentDir)) {
    Core.Unix.mkdir_p(Constant.currentDir);
  };

  if (Sys.file_exists(Constant.currentSymLinkPath)) {
    Sys.remove(Constant.currentSymLinkPath);
  };

  Core.Unix.symlink(
    ~target=binaryPath,
    ~link_name=Constant.currentSymLinkPath,
  );

  Console.log(
    <Pastel>
      "\nNow using Deno runtime "
      <Pastel color=Pastel.Cyan underline=true> version </Pastel>
      "."
    </Pastel>,
  );
};
