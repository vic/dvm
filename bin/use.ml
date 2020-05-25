open Cmdliner
open Dvm

let doc = "Set the Deno runtime version"

let info = Term.info "use" ~doc

let term =
  let doc = "Specify the version to use in $(docv)" in
  let docv = "VERSION" in
  Term.(
    const (fun version -> Use.command version)
    $
    let open Arg in
    required & pos 0 (some string) None & info [] ~doc ~docv)

let command = (term, info)
