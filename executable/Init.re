open Dvm;

let run = shell => {
  let output =
    switch (shell) {
    | "bash" => "export PATH=" ++ Constant.currentDir ++ ":$PATH"
    | "fish" => "set -gx PATH " ++ Constant.currentDir ++ " $PATH;"
    | _ => failwith(shell ++ " not supported")
    };

  Console.log(output);
};
