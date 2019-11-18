let mkdir = path => Core.Unix.mkdir_p(path);

let chmod = (path, perm) => Core.Unix.chmod(path, ~perm);

let osType = {
  Core.Unix.Utsname.sysname(Core.Unix.uname());
};

let archType = {
  Core.Unix.Utsname.machine(Core.Unix.uname());
};

let gunzip = path => Sys.command("gunzip " ++ path);
