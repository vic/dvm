let run = shell =>
  (
    switch (shell) {
    | "bash" => Printf.sprintf("export PATH=%s:$PATH", Constant.currentDir)
    | "fish" => Printf.sprintf("set -gx PATH %s $PATH;", Constant.currentDir)
    | _ => failwith(Printf.sprintf("%s is not supported.", shell))
    }
  )
  |> Console.log;
