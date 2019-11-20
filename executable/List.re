open Dvm;

let run = () => {
  let installDir = Filename.concat(Constant.dvmDir, "installs");

  if (!Sys.file_exists(installDir)) {
    Core.Unix.mkdir_p(installDir);
  };

  Core.Sys.ls_dir(installDir)
  |> List.rev
  |> List.iter(ver => ver |> Util.decorateString |> Console.log);
};
