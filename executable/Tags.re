let run = () =>
  Dvm.Tags.parse(
    Dvm.Http.get("https://api.github.com/repos/denoland/deno/releases"),
  );
