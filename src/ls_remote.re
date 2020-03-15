let decorateString = version =>
  <Pastel> <Pastel color=Pastel.Cyan> "* " </Pastel> version </Pastel>;

let printVersionList = body =>
  body
  |> Yojson.Safe.from_string
  |> Yojson.Safe.Util.map(obj => obj |> Yojson.Safe.Util.member("name"))
  |> Yojson.Safe.Util.to_list
  |> List.rev
  |> List.iter(version =>
       version
       |> Yojson.Safe.to_basic
       |> Yojson.Basic.to_string
       |> Util.stripQuotes
       |> decorateString
       |> Console.log
     );

let run = () =>
  Http.Curl.get("https://api.github.com/repos/denoland/deno/tags")
  |> printVersionList;
