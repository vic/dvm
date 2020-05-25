let command version =
  let install_version_dir = Filename.concat Config.install_dir version in
  let binary_path = Filename.concat install_version_dir "deno" in

  if not (Sys.file_exists binary_path) then (
    print_endline
      (Printf.sprintf "Deno runtime version %s does not exist" version);
    exit 1
  );

  if not (Sys.file_exists Config.current_dir) then
    Unix.mkdir Config.current_dir 0o755;

  if Sys.file_exists Config.current_symlink_path then
    Sys.remove Config.current_symlink_path;

  Unix.symlink binary_path Config.current_symlink_path ?to_dir:None;

  print_endline (Printf.sprintf "Now using Deno runtime %s" version)
