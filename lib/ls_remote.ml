open Lwt.Syntax

let print_version_list body =
  body |> Yojson.Safe.from_string
  |> Yojson.Safe.Util.map (fun json -> json |> Yojson.Safe.Util.member "name")
  |> Yojson.Safe.Util.to_list |> List.rev
  |> List.iter (fun version ->
         version |> Yojson.Safe.to_basic |> Yojson.Basic.to_string
         |> String_utility.strip_quotes |> print_endline)

let command () =
  let* body = Http.fetch "https://api.github.com/repos/denoland/deno/tags" in
  let () = print_version_list body in
  Lwt.return ()
