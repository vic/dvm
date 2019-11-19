let version = Dvm.Package_Info.version;

let doc = "Fast and simple Deno runtime version manager built with Native Reason.";

let man = [
  `S(Cmdliner.Manpage.s_bugs),
  `P(
    "Please report bugs using the issue tracker at https://github.com/imbsky/dvm/issues",
  ),
];

let default = {
  (
    Cmdliner.Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
    Cmdliner.Term.info("dvm", ~doc, ~man, ~version),
  );
};

module Commands = {
  let install = version => Install.run(version);
  let listAll = () => ListAll.run();
};

let install = {
  let doc = "Install a specific version of a Deno runtime.";
  Cmdliner.Term.(
    const(Commands.install)
    $ Cmdliner.Arg.(required & pos(0, some(string), None) & info([])),
    Cmdliner.Term.info("install", ~doc),
  );
};

let listAll = {
  let doc = "List all versions of a Deno runtime.";
  Cmdliner.Term.(
    app(const(Commands.listAll), const()),
    Cmdliner.Term.info("list-all", ~doc),
  );
};

let _ =
  Cmdliner.Term.eval_choice(default, [install, listAll])
  |> Cmdliner.Term.exit;
