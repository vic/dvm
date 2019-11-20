open Dvm;

let run = version => {
  let downloadUrl = Util.Install.createDownloadUrl(version);

  let installDir =
    Filename.concat(Filename.concat(Constant.dvmDir, "installs"), version);
  let gzipPath = Filename.concat(installDir, "deno.gz");
  let binaryPath = Filename.concat(installDir, "deno");

  if (!Sys.file_exists(Constant.dvmDir)) {
    Core.Unix.mkdir_p(Constant.dvmDir);
  };

  if (Sys.file_exists(installDir)) {
    Console.log(
      <Pastel>
        "Deno runtime version "
        <Pastel color=Pastel.Red underline=true> version </Pastel>
        " is already installed."
      </Pastel>,
    );
    exit(1);
  };

  Core.Unix.mkdir_p(installDir);
  Core_kernel.Out_channel.write_all(
    gzipPath,
    ~data=Http.Curl.get(downloadUrl),
  );

  let _ = Sys.command("gunzip " ++ gzipPath);
  Core.Unix.chmod(binaryPath, ~perm=755);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Red underline=true> version </Pastel>
      " was successfully installed!"
    </Pastel>,
  );
};
