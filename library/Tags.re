open Lwt;

let decorateString = version => {
  Pastel.(<Pastel> <Pastel color=Red> "* " </Pastel> version </Pastel>);
};

let stripQuotes = version => {
  let length = String.length(version) - 3;
  String.sub(version, 2, length);
};

let run =
  Cohttp_lwt_unix.Client.get(
    Uri.of_string("https://api.github.com/repos/denoland/deno/tags"),
  )
  >>= (
    ((_, body)) => {
      body
      |> Cohttp_lwt.Body.to_string
      >|= (
        body => {
          body
          |> Yojson.Safe.from_string
          |> Yojson.Safe.Util.map(x => x |> Yojson.Safe.Util.member("name"))
          |> Yojson.Safe.Util.to_list
          |> List.rev
          |> List.iter(x =>
               x
               |> Yojson.Safe.to_basic
               |> Yojson.Basic.to_string
               |> stripQuotes
               |> decorateString
               |> print_endline
             );
        }
      );
    }
  );
