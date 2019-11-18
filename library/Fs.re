let dvmDir = Filename.concat(Sys.getenv("HOME"), ".dvm");

let write = (path, contents) =>
  Core_kernel.Out_channel.write_all(path, ~data=contents);

let createDvmDir =
  if (!Sys.file_exists(dvmDir)) {
    print_endline(
      <Pastel>
        "The dvm directory doesn't exist. Creating "
        <Pastel color=Pastel.Red> dvmDir </Pastel>
        " now..."
      </Pastel>,
    );
    System.mkdir(dvmDir);
  };
