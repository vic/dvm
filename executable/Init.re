open Dvm;

let run = shell => {
  (
    switch (shell) {
    | "bash" => "export PATH=" ++ Constant.currentDir ++ ":$PATH"
    | "fish" => "set -gx PATH " ++ Constant.currentDir ++ " $PATH;"
    | _ => failwith(shell ++ " not supported")
    }
  )
  |> Console.log;
};
