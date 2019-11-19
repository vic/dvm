open Dvm;

let run = version => {
  let installDir =
    Filename.concat(Filename.concat(Constant.dvmDir, "installs"), version);
  let binaryPath = Filename.concat(installDir, "deno");
  let currentDir = Filename.concat(Constant.dvmDir, "current");
  let currentBinaryPath = Filename.concat(currentDir, "deno");

  Util.Use.createCurrentDir();

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
