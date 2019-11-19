let mkdir = Core.Unix.mkdir_p;

let rm = Sys.remove;

let rec rmrf = path =>
  Sys.is_directory(path)
    ? {
      Sys.readdir(path)
      |> Array.iter(filename => rmrf(Filename.concat(path, filename)));
      Unix.rmdir(path);
    }
    : Sys.remove(path);

let chmod = (path, perm) => Core.Unix.chmod(path, ~perm);

let os =
  switch (Core.Unix.Utsname.sysname(Core.Unix.uname())) {
  | "Darwin" => "osx"
  | "Linux" => "linux"
  | _ => failwith("Unsupported operating system")
  };

let arch =
  switch (Core.Unix.Utsname.machine(Core.Unix.uname())) {
  | "x86_64" => "x64"
  | _ => failwith("Unsupported architecture")
  };

let gunzip = path => Sys.command("gunzip " ++ path);
