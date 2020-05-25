open Cohttp
open Cohttp_lwt
open Cohttp_lwt_unix
open Lwt.Infix
open Lwt.Syntax

let is_redirection status = Code.is_redirection (Code.code_of_status status)

let get_location headers =
  match Header.get headers "location" with
  | None -> failwith "Redirect location not specified"
  | Some str -> str

let rec fetch uri =
  Client.get (Uri.of_string uri) >>= fun (response, body) ->
  if is_redirection response.status then
    get_location response.headers |> fun location -> fetch location
  else
    Body.to_string body >>= fun body -> Lwt.return body

let get uri ~path =
  let write_file path str =
    let* open_channel = Lwt_io.open_file ~mode:Lwt_io.Output path in
    let* () = Lwt_io.write open_channel str in
    let* () = Lwt_io.close open_channel in
    Lwt.return ()
  in
  let* str = fetch uri in
  let* () = write_file path str in
  Lwt.return ()
