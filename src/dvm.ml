let default =
  ( (let open Cmdliner.Term in
    ret (const (fun _ -> `Help (`Pager, None)) $ const ()))
  , Cmdliner.Term.info
      "dvm"
      ~doc:"Fast and simple Deno runtime version manager built with OCaml."
      ~man:
        [ `S Cmdliner.Manpage.s_bugs
        ; `P
            "Please report bugs using the issue tracker at \
             https://github.com/imbsky/dvm/issues"
        ]
      ~version:Package_info.version )
;;

module Commands = struct
  let init shell = Init.run shell
  let install version = Install.run version
  let ls_remote () = Ls_remote.run ()
  let ls () = Ls.run ()
  let uninstall version = Uninstall.run version
  let use version = Use.run version
end

let init =
  let open Cmdliner.Term in
  ( (const Commands.init
    $
    let open Cmdliner.Arg in
    required & pos 0 (some string) None & info [])
  , Cmdliner.Term.info "init" ~doc:"Print the path to a Deno runtime." )
;;

let install =
  let open Cmdliner.Term in
  ( (const Commands.install
    $
    let open Cmdliner.Arg in
    required
    & pos 0 (some string) None
    & info [] ~doc:"Specify the version to install in $(docv)." ~docv:"VERSION"
    )
  , Cmdliner.Term.info
      "install"
      ~doc:"Install a specific version of a Deno runtime." )
;;

let ls_remote =
  let open Cmdliner.Term in
  ( app (const Commands.ls_remote) (const ())
  , Cmdliner.Term.info
      "ls-remote"
      ~doc:"List all remote versions of a Deno runtime." )
;;

let ls =
  let open Cmdliner.Term in
  ( app (const Commands.ls) (const ())
  , Cmdliner.Term.info "ls" ~doc:"List installed versions of a Deno runtime." )
;;

let uninstall =
  let open Cmdliner.Term in
  ( (const Commands.uninstall
    $
    let open Cmdliner.Arg in
    required
    & pos 0 (some string) None
    & info
        []
        ~doc:"Specify the version to uninstall in $(docv)."
        ~docv:"VERSION")
  , Cmdliner.Term.info
      "uninstall"
      ~doc:"Uninstall a specific version of a Deno runtime." )
;;

let use =
  let open Cmdliner.Term in
  ( (const Commands.use
    $
    let open Cmdliner.Arg in
    required
    & pos 0 (some string) None
    & info [] ~doc:"Specify the version to use in $(docv)." ~docv:"VERSION")
  , Cmdliner.Term.info "use" ~doc:"Set the Deno runtime version." )
;;

let _ =
  Cmdliner.Term.eval_choice
    default
    [ init; install; ls_remote; ls; uninstall; use ]
  |> Cmdliner.Term.exit
;;
