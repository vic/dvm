open Dvm;

let run = version => {
  let downloadUrl = Util.Install.createDownloadUrl(version);

  let installDir =
    Filename.concat(Filename.concat(Constant.dvmDir, "installs"), version);
  let gzipPath = Filename.concat(installDir, "deno.gz");
  let binaryPath = Filename.concat(installDir, "deno");

  Util.Install.createDvmDir();
  System.mkdir(installDir);
  Fs.write(gzipPath, Http.Curl.get(downloadUrl));

  let _ = System.gunzip(gzipPath);
  System.chmod(binaryPath, 755);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Red underline=true> version </Pastel>
      " was successfully installed!"
    </Pastel>,
  );
};
