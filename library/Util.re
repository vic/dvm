module Install = {
  let createDownloadUrl = version =>
    "https://github.com/denoland/deno/releases/download/v"
    ++ version
    ++ "/"
    ++ "deno"
    ++ "_"
    ++ System.os
    ++ "_"
    ++ System.arch
    ++ ".gz";

  let createDvmDir = () =>
    if (!Sys.file_exists(Constant.dvmDir)) {
      Console.log(
        <Pastel>
          "The dvm directory does not exist. Creating "
          <Pastel color=Pastel.Red> Constant.dvmDir </Pastel>
          " now..."
        </Pastel>,
      );
      System.mkdir(Constant.dvmDir);
    };
};

module ListAll = {
  let stripQuotes = str => {
    String.sub(str, 2, String.length(str) - 3);
  };

  let decorateString = version => {
    <Pastel> <Pastel color=Pastel.Red> "* " </Pastel> version </Pastel>;
  };

  let parse = body => {
    body
    |> Yojson.Safe.from_string
    |> Yojson.Safe.Util.map(obj =>
         obj |> Yojson.Safe.Util.member("tag_name")
       )
    |> Yojson.Safe.Util.to_list
    |> List.rev
    |> List.iter(ver =>
         ver
         |> Yojson.Safe.to_basic
         |> Yojson.Basic.to_string
         |> stripQuotes
         |> decorateString
         |> print_endline
       );
  };
};

module Dotfile = {
  let denoVersion = Filename.concat(Sys.getcwd(), ".deno-version");
  let getVersion = () =>
    Sys.file_exists(denoVersion) === true
      ? denoVersion |> Fs.read |> String.trim
      : failwith("Could not find .deno-version file");
};

module Use = {
  let currentDir = Filename.concat(Constant.dvmDir, "current");
  let createCurrentDir = () =>
    if (!Sys.file_exists(currentDir)) {
      Console.log(
        <Pastel>
          "The current directory does not exist. Creating "
          <Pastel color=Pastel.Red> currentDir </Pastel>
          " now..."
        </Pastel>,
      );
      System.mkdir(currentDir);
    };
};
