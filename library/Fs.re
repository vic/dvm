let dvmDir = Filename.concat(Sys.getenv("HOME"), ".dvm");

let write = (path, contents) =>
  Core_kernel.Out_channel.write_all(path, ~data=contents);

let createDvmDir = {
  if%lwt (Lwt_unix.file_exists(dvmDir) |> Lwt.map(x => !x)) {
    print_endline(
      Pastel.(
        <Pastel>
          "The dvm directory doesn't exist. Creating "
          <Pastel color=Red> dvmDir </Pastel>
          " now..."
        </Pastel>
      ),
    );
    let%lwt _ = System.exec([|"mkdir", "-p", dvmDir|]);
    Lwt.return();
  } else {
    Lwt.return();
  };
};
