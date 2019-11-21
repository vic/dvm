open Dvm;

let run = version => {
  let installVersionDir = Filename.concat(Constant.installDir, version);
  let binaryPath = Filename.concat(installVersionDir, "deno");
  let currentBinaryPath = Filename.concat(Constant.currentDir, "deno");

  if (!Sys.file_exists(installVersionDir)) {
    Console.log(
      <Pastel>
        "Deno runtime version "
        <Pastel color=Pastel.Red underline=true> version </Pastel>
        " does not exist."
      </Pastel>,
    );
    exit(1);
  };

  if (Sys.file_exists(currentBinaryPath)) {
    if (Unix.readlink(currentBinaryPath) == binaryPath) {
      Core.Unix.unlink(currentBinaryPath);
    };
  };

  System.rmrf(installVersionDir);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Cyan underline=true> version </Pastel>
      " has been uninstalled."
    </Pastel>,
  );
};
