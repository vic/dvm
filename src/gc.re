let containsSubstring = (search, pattern) =>
  Core.String.substr_index(search, ~pattern) != None;

let removeUnusedVersion = (version, isUsed) =>
  if (isUsed) {
    Console.log(
      <Pastel>
        "\n"
        <Pastel color=Pastel.Cyan underline=true> version </Pastel>
        " was not removed because it's the current version."
      </Pastel>,
    );
  } else {
    System.rmrf(Filename.concat(Constant.installDir, version));
    Console.log(
      <Pastel>
        <Pastel color=Pastel.Cyan underline=true> version </Pastel>
        " was successfully purged!"
      </Pastel>,
    );
  };

let run = () =>
  if (Sys.file_exists(Constant.currentSymLinkPath)) {
    Core.Sys.ls_dir(Constant.installDir)
    |> List.rev
    |> List.iter(version =>
         version
         |> containsSubstring(Constant.currentSymLinkPath |> Unix.readlink)
         |> removeUnusedVersion(version)
       );
  } else {
    Console.log("Could not run gc because the current version is not set.");
    exit(1);
  };
