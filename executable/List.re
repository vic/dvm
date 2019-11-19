open Dvm;

let run = () =>
  Core.Sys.ls_dir(Filename.concat(Constant.dvmDir, "installs"))
  |> List.rev
  |> List.iter(ver => ver |> Util.decorateString |> Console.log);
