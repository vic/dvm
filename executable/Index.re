open Dvm;

let default = {
  (
    Cmdliner.Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
    Cmdliner.Term.info(
      "dvm",
      ~doc=
        "Fast and simple Deno runtime version manager built with Native Reason.",
      ~man=[
        `S(Cmdliner.Manpage.s_bugs),
        `P(
          "Please report bugs using the issue tracker at https://github.com/imbsky/dvm/issues",
        ),
      ],
      ~version=Package_Info.version,
    ),
  );
};

module Commands = {
  let install = version => Install.run(version);
  let listAll = () => ListAll.run();
};

let install = {
  Cmdliner.Term.(
    const(Commands.install)
    $ Cmdliner.Arg.(
        required
        & pos(0, some(string), None)
        & info(
            [],
            ~doc="Specify the version to install in $(docv).",
            ~docv="VERSION",
          )
      ),
    Cmdliner.Term.info(
      "install",
      ~doc="Install a specific version of a Deno runtime.",
    ),
  );
};

let listAll = {
  Cmdliner.Term.(
    app(const(Commands.listAll), const()),
    Cmdliner.Term.info(
      "list-all",
      ~doc="List all versions of a Deno runtime.",
    ),
  );
};

let _ =
  Cmdliner.Term.eval_choice(default, [install, listAll])
  |> Cmdliner.Term.exit;
