open Cmdliner
open Dvm

let doc = "List all remote versions of the Deno runtime"

let info = Term.info "ls-remote" ~doc

let term =
  Term.app
    (Term.const (fun () -> Lwt_main.run (Ls_remote.command ())))
    (Term.const ())

let command = (term, info)
