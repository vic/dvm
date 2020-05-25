open Cmdliner
open Dvm

let doc = "Uninstall a specific version of the Deno runtime"

let info = Term.info "uninstall" ~doc

let term =
  let doc = "Specify the version to uninstall in $(docv)" in
  let docv = "VERSION" in
  Term.(
    const (fun version -> Uninstall.command version)
    $
    let open Arg in
    required & pos 0 (some string) None & info [] ~doc ~docv)

let command = (term, info)
