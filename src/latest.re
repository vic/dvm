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

let getLatestVersion = () =>
  Http.Curl.get("https://api.github.com/repos/denoland/deno/releases/latest")
  |> Yojson.Safe.from_string
  |> Yojson.Safe.Util.member("tag_name")
  |> Yojson.Safe.to_basic
  |> Yojson.Basic.to_string
  |> Util.stripQuotes;

let run = () => Install.run(getLatestVersion());
