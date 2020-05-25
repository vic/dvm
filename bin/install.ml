open Cmdliner
open Dvm

let doc = "Install a specific version of the Deno runtime"

let info = Term.info "install" ~doc

let term =
  let doc = "Specify the version to install in $(docv)" in
  let docv = "VERSION" in
  Term.(
    const (fun version -> Lwt_main.run (Install.command version))
    $
    let open Arg in
    required & pos 0 (some string) None & info [] ~doc ~docv)

let command = (term, info)
