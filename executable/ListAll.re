let run = () =>
  Dvm.Version.parse(
    Dvm.Http.get("https://api.github.com/repos/denoland/deno/releases"),
  );
