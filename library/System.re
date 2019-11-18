let exec = cmd => {
  let%lwt _ = Lwt_process.exec(("", cmd));
  Lwt.return();
};
