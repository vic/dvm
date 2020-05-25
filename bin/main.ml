open Cmdliner

let default =
  let doc = "Fast and simple Deno runtime version manager written in OCaml" in
  let version = Dvm.Version.get () in
  let term =
    let open Term in
    ret (const (fun _ -> `Help (`Pager, None)) $ const ())
  in
  ( term
  , Term.info "dvm" ~doc ~version
      ~man:
        [ `S Manpage.s_description
        ; `P
            "Please report bugs using the issue tracker at \
             https://github.com/imbsky/dvm/issues"
        ] )

let all =
  [ Gc.command
  ; Init.command
  ; Install.command
  ; Latest.command
  ; Ls_remote.command
  ; Ls.command
  ; Uninstall.command
  ; Use.command
  ]

let () = Cmdliner.Term.exit (Term.eval_choice default all)
