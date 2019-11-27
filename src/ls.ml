let decorateString version = "* " ^ version

let run () =
  if not (Sys.file_exists Constant.installDir)
  then Core.Unix.mkdir_p Constant.installDir;
  Core.Sys.ls_dir Constant.installDir
  |> List.rev
  |> List.iter (fun ver -> ver |> decorateString |> print_endline)
;;
