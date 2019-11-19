open Dvm;

let run = () =>
  Util.ListAll.parse(
    Http.Curl.get("https://api.github.com/repos/denoland/deno/releases"),
  );
