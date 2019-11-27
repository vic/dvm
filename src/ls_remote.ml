let decorateString version = "* " ^ version
let stripQuotes str = String.sub str 2 (String.length str - 3)

let jsonParse body =
  body
  |> Yojson.Safe.from_string
  |> Yojson.Safe.Util.map (fun obj -> obj |> Yojson.Safe.Util.member "name")
  |> Yojson.Safe.Util.to_list
  |> List.rev
  |> List.iter (fun ver ->
         ver
         |> Yojson.Safe.to_basic
         |> Yojson.Basic.to_string
         |> stripQuotes
         |> decorateString
         |> print_endline)
;;

let run () =
  Http.Curl.get "https://api.github.com/repos/denoland/deno/tags" |> jsonParse
;;
