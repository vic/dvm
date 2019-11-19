let rec rmrf = path =>
  Sys.is_directory(path)
    ? {
      Sys.readdir(path)
      |> Array.iter(filename => rmrf(Filename.concat(path, filename)));
      Unix.rmdir(path);
    }
    : Sys.remove(path);

let sysname = Core.Unix.Utsname.sysname(Core.Unix.uname());
let machine = Core.Unix.Utsname.machine(Core.Unix.uname());

let os =
  switch (sysname) {
  | "Darwin" => "osx"
  | "Linux" => "linux"
  | _ => failwith(sysname ++ " not supported")
  };

let arch =
  switch (machine) {
  | "x86_64" => "x64"
  | _ => failwith(machine ++ " not supported")
  };
