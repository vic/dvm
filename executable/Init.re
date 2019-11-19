open Dvm;

let run = shell => {
  let output =
    switch (shell) {
    | "bash" =>
      "export PATH="
      ++ Filename.concat(Constant.dvmDir, "current")
      ++ ":$PATH"
    | "fish" =>
      "set -gx PATH "
      ++ Filename.concat(Constant.dvmDir, "current")
      ++ " $PATH;"
    | _ => failwith(shell ++ " not supported")
    };

  Console.log(output);
};
