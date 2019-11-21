open Dvm;

let run = () =>
  Http.Curl.get("https://api.github.com/repos/denoland/deno/releases")
  |> Json.ListAll.parse;
