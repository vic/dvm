open Cmdliner
open Dvm

let doc = "Install the latest version of the Deno runtime"

let info = Term.info "latest" ~doc

let term =
  Term.app
    (Term.const (fun () -> Lwt_main.run (Latest.command ())))
    (Term.const ())

let command = (term, info)
