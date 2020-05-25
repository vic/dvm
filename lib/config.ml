let install_dir_path =
  match Option.is_some (Sys.getenv_opt "DVM_INSTALL_DIR") with
  | true -> Sys.getenv "DVM_INSTALL_DIR"
  | false -> Sys.getenv "HOME"

let root_dir = Filename.concat install_dir_path ".dvm"

let install_dir = Filename.concat root_dir "installs"

let current_dir = Filename.concat root_dir "current"

let current_symlink_path = Filename.concat current_dir "deno"
