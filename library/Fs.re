let write = (path, contents) => {
  let%lwt file = Lwt_io.open_file(~mode=Lwt_io.Output, path);
  let%lwt () = Lwt_io.write(file, contents);
  let%lwt () = Lwt_io.close(file);
  Lwt.return();
};
