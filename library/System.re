let mkdir = Core.Unix.mkdir_p;

let rm = Unix.unlink;

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
