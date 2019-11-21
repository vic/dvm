open Dvm;

let run = version => {
  let downloadUrl = Util.Install.createDownloadUrl(version);
  let installVersionDir = Filename.concat(Constant.installDir, version);
  let binaryPath = Filename.concat(installVersionDir, "deno");

  if (!Sys.file_exists(Constant.dvmDir)) {
    Core.Unix.mkdir_p(Constant.dvmDir);
  };

  if (Sys.file_exists(installVersionDir)) {
    Console.log(
      <Pastel>
        "Deno runtime version "
        <Pastel color=Pastel.Red underline=true> version </Pastel>
        " is already installed."
      </Pastel>,
    );
    exit(1);
  };

  Core.Unix.mkdir_p(installVersionDir);
  Core_kernel.Out_channel.write_all(
    binaryPath,
    ~data=Rresult.R.get_ok(Ezgzip.decompress(Http.Curl.get(downloadUrl))),
  );

  Core.Unix.chmod(binaryPath, ~perm=755);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Red underline=true> version </Pastel>
      " was successfully installed!"
    </Pastel>,
  );
};
