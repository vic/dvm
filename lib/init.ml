let command shell =
  ( match shell with
  | "bash" -> Printf.sprintf "export PATH=%s:$PATH" Config.current_dir
  | "fish" -> Printf.sprintf "set -gx PATH %s $PATH;" Config.current_dir
  | _ -> failwith (Printf.sprintf "%s is not supported" shell) )
  |> print_endline
