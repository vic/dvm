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
