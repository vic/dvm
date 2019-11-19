open Dvm;

let run = version => {
  let installDir =
    Filename.concat(Filename.concat(Constant.dvmDir, "installs"), version);
  let binaryPath = Filename.concat(installDir, "deno");
  let currentDir = Filename.concat(Constant.dvmDir, "current");
  let currentBinaryPath = Filename.concat(currentDir, "deno");

  Util.Use.createCurrentDir();

  if (Sys.file_exists(currentBinaryPath)) {
    System.rm(currentBinaryPath);
  };

  Console.log(
    <Pastel>
      "Creating "
      <Pastel color=Pastel.Cyan> binaryPath </Pastel>
      " as a symbolic link to the "
      <Pastel color=Pastel.Cyan> currentBinaryPath </Pastel>
    </Pastel>,
  );

  Fs.createSymlink(binaryPath, currentBinaryPath);

  Console.log(<Pastel> "Symbolic link was successfully created!" </Pastel>);
};
