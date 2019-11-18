let mkdir = path => Core.Unix.mkdir_p(path);

let chmod = (path, perm) => Core.Unix.chmod(path, ~perm);

let uname = {
  Core.Unix.Utsname.sysname(Core.Unix.uname());
};

let gunzip = path => Sys.command("gunzip " ++ path);
