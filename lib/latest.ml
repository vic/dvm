open Lwt.Syntax

let get_latest_version body =
  body |> Yojson.Safe.from_string
  |> Yojson.Safe.Util.member "tag_name"
  |> Yojson.Safe.to_basic |> Yojson.Basic.to_string
  |> String_utility.strip_quotes

let command () =
  let* body =
    Http.fetch "https://api.github.com/repos/denoland/deno/releases/latest"
  in
  let version = get_latest_version body in
  let* () = Install.command version in
  Lwt.return ()
