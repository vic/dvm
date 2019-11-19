let createDvmDir = () =>
  if (!Sys.file_exists(Constants.dvmDir)) {
    Console.log(
      <Pastel>
        "The dvm directory doesn't exist. Creating "
        <Pastel color=Pastel.Cyan> Constants.dvmDir </Pastel>
        " now..."
      </Pastel>,
    );
    System.mkdir(Constants.dvmDir);
  };

let run = version => {
  let os =
    switch (System.osType) {
    | "Darwin" => "osx"
    | "Linux" => "linux"
    | _ => "other"
    };

  let arch =
    switch (System.archType) {
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

  createDvmDir();
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
