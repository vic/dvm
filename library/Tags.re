open Lwt;

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
          |> Yojson.Safe.to_basic
          |> Yojson.Basic.to_string
          |> print_endline;
        }
      );
    }
  );
