let getLatestVersion = () =>
  Http.Curl.get("https://api.github.com/repos/denoland/deno/releases/latest")
  |> Yojson.Safe.from_string
  |> Yojson.Safe.Util.member("tag_name")
  |> Yojson.Safe.to_basic
  |> Yojson.Basic.to_string
  |> Util.stripQuotes;

let run = () => getLatestVersion() |> Install.run;
