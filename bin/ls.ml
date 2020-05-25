open Cmdliner
open Dvm

let doc = "List installed versions of the Deno runtime"

let info = Term.info "ls" ~doc

let term = Term.app (Term.const (fun () -> Ls.command ())) (Term.const ())

let command = (term, info)
