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
  let init = shell => Init.run(shell);
  let install = version => Install.run(version);
  let list = () => List.run();
  let listAll = () => ListAll.run();
  let uninstall = version => Uninstall.run(version);
  let use = version => Use.run(version);
};

let init = {
  Cmdliner.Term.(
    const(Commands.init)
    $ Cmdliner.Arg.(required & pos(0, some(string), None) & info([])),
    Cmdliner.Term.info("init", ~doc="Output the path for your shell."),
  );
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

let list = {
  Cmdliner.Term.(
    app(const(Commands.list), const()),
    Cmdliner.Term.info("list", ~doc="List all versions of a Deno runtime."),
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

let uninstall = {
  Cmdliner.Term.(
    const(Commands.uninstall)
    $ Cmdliner.Arg.(
        required
        & pos(0, some(string), None)
        & info(
            [],
            ~doc="Specify the version to uninstall in $(docv).",
            ~docv="VERSION",
          )
      ),
    Cmdliner.Term.info(
      "uninstall",
      ~doc="Uninstall a specific version of a Deno runtime.",
    ),
  );
};

let use = {
  Cmdliner.Term.(
    const(Commands.use)
    $ Cmdliner.Arg.(
        required
        & pos(0, some(string), None)
        & info(
            [],
            ~doc="Specify the version to use in $(docv).",
            ~docv="VERSION",
          )
      ),
    Cmdliner.Term.info(
      "use",
      ~doc="Set a specific version of a Deno runtime.",
    ),
  );
};

let _ =
  Cmdliner.Term.eval_choice(
    default,
    [init, install, list, listAll, uninstall, use],
  )
  |> Cmdliner.Term.exit;
