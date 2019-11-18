let exec = cmd => {
  let%lwt _ = Lwt_process.exec(("", cmd));
  Lwt.return();
};

let mkdir = path => Core.Unix.mkdir_p(path);

let chmod = (path, perm) => Core.Unix.chmod(path, ~perm);
