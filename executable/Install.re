open Dvm;

let run = version => {
  let downloadUrl =
    "https://github.com/denoland/deno/releases/download/v"
    ++ version
    ++ "/"
    ++ "deno"
    ++ "_"
    ++ System.os
    ++ "_"
    ++ System.arch
    ++ ".gz";

  let installDir =
    Filename.concat(Filename.concat(Constants.dvmDir, "installs"), version);
  let gzipPath = Filename.concat(installDir, "deno.gz");
  let binaryPath = Filename.concat(installDir, "deno");

  Console.log(
    <Pastel>
      "Downloading "
      <Pastel color=Pastel.Cyan> downloadUrl </Pastel>
      " to "
      <Pastel color=Pastel.Cyan> installDir </Pastel>
    </Pastel>,
  );

  Fs.createDvmDir();
  System.mkdir(installDir);
  Fs.write(gzipPath, Http.get(downloadUrl));

  Console.log(
    <Pastel>
      "Extracting "
      <Pastel color=Pastel.Cyan> gzipPath </Pastel>
      " to "
      <Pastel color=Pastel.Cyan> binaryPath </Pastel>
    </Pastel>,
  );

  let _ = System.gunzip(gzipPath);
  System.chmod(binaryPath, 755);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Cyan> version </Pastel>
      " was successfully installed!"
    </Pastel>,
  );
};
