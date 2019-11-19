open Dvm;

let run = version => {
  let installDir =
    Filename.concat(Filename.concat(Constant.dvmDir, "installs"), version);

  if (!Sys.file_exists(installDir)) {
    Console.log(
      <Pastel>
        "Deno runtime version "
        <Pastel color=Pastel.Red underline=true> version </Pastel>
        " does not exist."
      </Pastel>,
    );
    exit(1);
  };

  System.rmrf(installDir);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Red underline=true> version </Pastel>
      " has been uninstalled."
    </Pastel>,
  );
};
