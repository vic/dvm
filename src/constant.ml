let installDirPath =
  match Option.is_some (Sys.getenv_opt "DVM_INSTALL_DIR") with
  | true -> Sys.getenv "DVM_INSTALL_DIR"
  | false -> Sys.getenv "HOME"
;;

let dvmDir = Filename.concat installDirPath ".dvm"
let installDir = Filename.concat dvmDir "installs"
let currentDir = Filename.concat dvmDir "current"
