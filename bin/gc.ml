open Cmdliner
open Dvm

let doc = "Purge unused versions of the Deno runtime"

let info = Term.info "gc" ~doc

let term = Term.app (Term.const (fun () -> Gc.command ())) (Term.const ())

let command = (term, info)
