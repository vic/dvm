let exec = cmd => {
  let%lwt _ = Lwt_process.exec(("", cmd));
  Lwt.return();
};

let chmod = (path, perm) => Core.Unix.chmod(path, ~perm);
