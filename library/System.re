let mkdir = path => Core.Unix.mkdir_p(path);

let chmod = (path, perm) => Core.Unix.chmod(path, ~perm);

let gunzip = path => Sys.command("gunzip " ++ path);
