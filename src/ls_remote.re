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

let decorateString = version => {
  <Pastel> <Pastel color=Pastel.Cyan> "* " </Pastel> version </Pastel>;
};

let stripQuotes = str => {
  String.sub(str, 2, String.length(str) - 3);
};

let jsonParse = body => {
  body
  |> Yojson.Safe.from_string
  |> Yojson.Safe.Util.map(obj => obj |> Yojson.Safe.Util.member("name"))
  |> Yojson.Safe.Util.to_list
  |> List.rev
  |> List.iter(ver =>
       ver
       |> Yojson.Safe.to_basic
       |> Yojson.Basic.to_string
       |> stripQuotes
       |> decorateString
       |> Console.log
     );
};

let run = () =>
  Http.Curl.get("https://api.github.com/repos/denoland/deno/tags")
  |> jsonParse;
