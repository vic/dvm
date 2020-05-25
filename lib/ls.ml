let command () =
  if Sys.file_exists Config.install_dir then
    Sys.readdir Config.install_dir
    |> Array.to_list |> List.rev
    |> List.iter (fun version -> print_endline version)
