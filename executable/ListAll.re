open Dvm;

let run = () =>
  Util.ListAll.parse(
    Http.get("https://api.github.com/repos/denoland/deno/releases"),
  );
