let contains_substring search pattern =
  Base.String.substr_index search ~pattern != None

let remove_unused_version version is_used =
  if is_used then
    print_endline
      (Printf.sprintf "%s was not removed because it's the current version"
         version)
  else (
    System.FileOperation.rmrf (Filename.concat Config.install_dir version);
    print_endline (Printf.sprintf "%s was successfully purged!" version)
  )

let command () =
  if Sys.file_exists Config.current_symlink_path then
    Sys.readdir Config.install_dir
    |> Array.to_list |> List.rev
    |> List.iter (fun version ->
           version
           |> contains_substring (Unix.readlink Config.current_symlink_path)
           |> remove_unused_version version)
  else (
    print_endline "Could not run gc because the current version is not set";
    exit 1
  )
