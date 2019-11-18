open Lwt;

let releaseUrl = "https://api.github.com/repos/denoland/deno/releases";

let stripQuotes = str => {
  String.sub(str, 2, String.length(str) - 3);
};

let decorateString = version => {
  Pastel.(
    <Pastel color=WhiteBright>
      <Pastel color=Red> "* " </Pastel>
      version
    </Pastel>
  );
};

let run =
  Cohttp_lwt_unix.Client.get(Uri.of_string(releaseUrl))
  >>= (
    ((_, body)) => {
      body
      |> Cohttp_lwt.Body.to_string
      >|= (
        body => {
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
        }
      );
    }
  );
