let decorateString = version => {
  <Pastel> <Pastel color=Pastel.Red> "* " </Pastel> version </Pastel>;
};

module Install = {
  let createDownloadUrl = version =>
    "https://github.com/denoland/deno/releases/download/v"
    ++ version
    ++ "/deno_"
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
      Core.Unix.mkdir_p(Constant.dvmDir);
    };
};

module ListAll = {
  let stripQuotes = str => {
    String.sub(str, 2, String.length(str) - 3);
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
         |> Console.log
       );
  };
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
      Core.Unix.mkdir_p(currentDir);
    };
};
