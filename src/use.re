let run = version => {
  let installVersionDir = Filename.concat(Constant.installDir, version);
  let binaryPath = Filename.concat(installVersionDir, "deno");

  if (!Sys.file_exists(binaryPath)) {
    Console.log(
      <Pastel>
        "Deno runtime version "
        <Pastel color=Pastel.Cyan underline=true> version </Pastel>
        " does not exist."
      </Pastel>,
    );
    exit(1);
  };

  if (!Sys.file_exists(Constant.currentDir)) {
    Core.Unix.mkdir_p(Constant.currentDir);
  };

  if (Sys.file_exists(Constant.currentSymLinkPath)) {
    Sys.remove(Constant.currentSymLinkPath);
  };

  Core.Unix.symlink(
    ~target=binaryPath,
    ~link_name=Constant.currentSymLinkPath,
  );

  Console.log(
    <Pastel>
      "\nNow using Deno runtime "
      <Pastel color=Pastel.Cyan underline=true> version </Pastel>
      "."
    </Pastel>,
  );
};
