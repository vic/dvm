let write = (path, contents) =>
  Core_kernel.Out_channel.write_all(path, ~data=contents);

let createDvmDir = () =>
  if (!Sys.file_exists(Constants.dvmDir)) {
    Console.log(
      <Pastel>
        "The dvm directory doesn't exist. Creating "
        <Pastel color=Pastel.Cyan> Constants.dvmDir </Pastel>
        " now..."
      </Pastel>,
    );
    System.mkdir(Constants.dvmDir);
  };
