open Dvm;

let run = () => {
  if (!Sys.file_exists(Constant.installDir)) {
    Core.Unix.mkdir_p(Constant.installDir);
  };

  Core.Sys.ls_dir(Constant.installDir)
  |> List.rev
  |> List.iter(ver => ver |> Util.decorateString |> Console.log);
};
