let run shell =
  (match shell with
  | "bash" -> "export PATH=" ^ Constant.currentDir ^ ":$" ^ "PATH"
  | "fish" -> "set -gx PATH " ^ Constant.currentDir ^ " $" ^ "PATH;"
  | _ -> failwith (shell ^ " not supported"))
  |> print_endline
;;
