open Dvm;

let run = () =>
  Version.parse(
    Http.get("https://api.github.com/repos/denoland/deno/releases"),
  );
