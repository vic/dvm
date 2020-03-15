let run = version => {
  let installVersionDir = Filename.concat(Constant.installDir, version);
  let binaryPath = Filename.concat(installVersionDir, "deno");

  if (!Sys.file_exists(installVersionDir)) {
    Console.log(
      <Pastel>
        "\nDeno runtime version "
        <Pastel color=Pastel.Cyan underline=true> version </Pastel>
        " does not exist."
      </Pastel>,
    );
    exit(1);
  };

  if (Sys.file_exists(Constant.currentSymLinkPath)) {
    if (Unix.readlink(Constant.currentSymLinkPath) == binaryPath) {
      Core.Unix.unlink(Constant.currentSymLinkPath);
    };
  };

  System.rmrf(installVersionDir);

  Console.log(
    <Pastel>
      "\nDeno runtime version "
      <Pastel color=Pastel.Cyan underline=true> version </Pastel>
      " has been successfully uninstalled!"
    </Pastel>,
  );
};
