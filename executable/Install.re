open Dvm;

let run = version => {
  let downloadUrl = Util.Install.createDownloadUrl(version);

  let installDir =
    Filename.concat(Filename.concat(Constant.dvmDir, "installs"), version);
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
  Fs.write(gzipPath, Http.Curl.get(downloadUrl));

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
