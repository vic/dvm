open Dvm;

let run = version => {
  let installVersionDir = Filename.concat(Constant.installDir, version);
  let binaryPath = Filename.concat(installVersionDir, "deno");
  let currentBinaryPath = Filename.concat(Constant.currentDir, "deno");

  if (!Sys.file_exists(Constant.currentDir)) {
    Core.Unix.mkdir_p(Constant.currentDir);
  };

  if (Sys.file_exists(currentBinaryPath)) {
    Sys.remove(currentBinaryPath);
  };

  Core.Unix.symlink(~target=binaryPath, ~link_name=currentBinaryPath);

  Console.log(
    <Pastel>
      "Now using Deno runtime "
      <Pastel color=Pastel.Red underline=true> version </Pastel>
    </Pastel>,
  );
};
