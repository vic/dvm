let dvmDir = Filename.concat(Sys.getenv("HOME"), ".dvm");

let write = (path, contents) => {
  let%lwt file = Lwt_io.open_file(~mode=Lwt_io.Output, path);
  let%lwt () = Lwt_io.write(file, contents);
  let%lwt () = Lwt_io.close(file);
  Lwt.return();
};

let createDvmDir = {
  let exists = Lwt_unix.file_exists(dvmDir);
  if%lwt (exists |> Lwt.map(x => !x)) {
    print_endline(
      Pastel.(
        <Pastel>
          "The dvm directory doesn't exist. Creating "
          <Pastel color=Red> dvmDir </Pastel>
          " now..."
        </Pastel>
      ),
    );
    let%lwt _ = Lwt_process.exec(("", [|"mkdir", "-p", dvmDir|]));
    Lwt.return();
  } else {
    Lwt.return();
  };
};
