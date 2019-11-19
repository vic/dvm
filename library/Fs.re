let write = (path, contents) =>
  Core_kernel.Out_channel.write_all(path, ~data=contents);

let createDvmDir = () =>
  if (!Sys.file_exists(Constant.dvmDir)) {
    Console.log(
      <Pastel>
        "The dvm directory doesn't exist. Creating "
        <Pastel color=Pastel.Cyan> Constant.dvmDir </Pastel>
        " now..."
      </Pastel>,
    );
    System.mkdir(Constant.dvmDir);
  };
