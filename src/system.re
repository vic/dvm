let rec rmrf = path =>
  Sys.is_directory(path)
    ? {
      Sys.readdir(path)
      |> Array.iter(filename => rmrf(Filename.concat(path, filename)));
      Unix.rmdir(path);
    }
    : Sys.remove(path);

let uname = Core.Unix.uname();
let sysname = Core.Unix.Utsname.sysname(uname);
let machine = Core.Unix.Utsname.machine(uname);

let os =
  switch (sysname) {
  | "Darwin" => "osx"
  | "Linux" => "linux"
  | _ => failwith(Printf.sprintf("%s is not supported.", sysname))
  };

let arch =
  switch (machine) {
  | "x86_64" => "x64"
  | _ => failwith(Printf.sprintf("%s is not supported.", machine))
  };
