open Cmdliner
open Dvm

let doc = "Print the path to the Deno runtime"

let info = Term.info "init" ~doc

let term =
  Term.(
    const (fun version -> Init.command version)
    $
    let open Arg in
    required & pos 0 (some string) None & info [])

let command = (term, info)
