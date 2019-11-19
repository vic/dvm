let run = version => {
  let os =
    switch (Dvm.System.osType) {
    | "Darwin" => "osx"
    | "Linux" => "linux"
    | _ => "other"
    };

  let arch =
    switch (Dvm.System.archType) {
    | "x86_64" => "x64"
    | _ => "other"
    };

  let downloadUrl =
    "https://github.com/denoland/deno/releases/download/v"
    ++ version
    ++ "/"
    ++ "deno"
    ++ "_"
    ++ os
    ++ "_"
    ++ arch
    ++ ".gz";

  let installDir =
    Filename.concat(
      Filename.concat(Dvm.Constants.dvmDir, "installs"),
      version,
    );
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

  Dvm.Fs.createDvmDir();
  Dvm.System.mkdir(installDir);
  Dvm.Fs.write(gzipPath, Dvm.Http.get(downloadUrl));

  Console.log(
    <Pastel>
      "Extracting "
      <Pastel color=Pastel.Cyan> gzipPath </Pastel>
      " to "
      <Pastel color=Pastel.Cyan> binaryPath </Pastel>
    </Pastel>,
  );

  let _ = Dvm.System.gunzip(gzipPath);
  Dvm.System.chmod(binaryPath, 755);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Cyan> version </Pastel>
      " was successfully installed!"
    </Pastel>,
  );
};
