let command version =
  let install_version_dir = Filename.concat Config.install_dir version in
  let binaryPath = Filename.concat install_version_dir "deno" in

  if not (Sys.file_exists install_version_dir) then (
    print_endline
      (Printf.sprintf "Deno runtime version %s does not exist" version);
    exit 1
  );

  if Sys.file_exists Config.current_symlink_path then
    if Unix.readlink Config.current_symlink_path = binaryPath then
      Unix.unlink Config.current_symlink_path;

  System.FileOperation.rmrf install_version_dir;

  print_endline
    (Printf.sprintf "Deno runtime version %s has been successfully uninstalled!"
       version)
