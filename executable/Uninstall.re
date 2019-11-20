open Dvm;

let run = version => {
  let installVersionDir = Filename.concat(Constant.installDir, version);

  if (!Sys.file_exists(installVersionDir)) {
    Console.log(
      <Pastel>
        "Deno runtime version "
        <Pastel color=Pastel.Red underline=true> version </Pastel>
        " does not exist."
      </Pastel>,
    );
    exit(1);
  };

  System.rmrf(installVersionDir);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Red underline=true> version </Pastel>
      " has been uninstalled."
    </Pastel>,
  );
};
