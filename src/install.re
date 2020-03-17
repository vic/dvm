let createDownloadUrl = version =>
  Printf.sprintf(
    "https://github.com/denoland/deno/releases/download/v%s/deno_%s_%s.gz",
    version,
    System.os,
    System.arch,
  );

let get_ok =
  fun
  | Ok(v) => v
  | Error(_) =>
    failwith("This version does not exist in the GitHub release.");

let run = version => {
  let downloadUrl = createDownloadUrl(version);
  let installVersionDir = Filename.concat(Constant.installDir, version);
  let binaryPath = Filename.concat(installVersionDir, "deno");

  if (!Sys.file_exists(Constant.dvmDir)) {
    Core.Unix.mkdir_p(Constant.dvmDir);
  };

  if (Sys.file_exists(installVersionDir)) {
    Console.log(
      <Pastel>
        "\nDeno runtime version "
        <Pastel color=Pastel.Cyan underline=true> version </Pastel>
        " is already installed."
      </Pastel>,
    );
    exit(1);
  };

  Core.Unix.mkdir_p(installVersionDir);

  Core.Out_channel.write_all(
    binaryPath,
    ~data=
      Http.Curl.get(downloadUrl, ~progress=true)
      |> Ezgzip.decompress
      |> get_ok,
  );

  Core.Unix.chmod(binaryPath, ~perm=755);

  Console.log(
    <Pastel>
      "\nDeno runtime version "
      <Pastel color=Pastel.Cyan underline=true> version </Pastel>
      " was successfully installed!"
    </Pastel>,
  );
};
