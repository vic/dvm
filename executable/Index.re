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
  let tags = () => Tags.run();
  let install = version => Install.run(version);
};

let tags = {
  let doc = "List all the tags via GitHub API";
  Cmdliner.Term.(
    app(const(Commands.tags), const()),
    Cmdliner.Term.info("tags", ~doc),
  );
};

let install = {
  let version =
    Cmdliner.Arg.(
      required & pos(0, some(string), None) & info([], ~doc="VERSION")
    );
  Cmdliner.Term.(
    const(Commands.install) $ version,
    Cmdliner.Term.info("install"),
  );
};

let _ =
  Cmdliner.Term.eval_choice(default, [tags, install]) |> Cmdliner.Term.exit;
