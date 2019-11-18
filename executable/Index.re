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
  let tags = () => Lwt_main.run(Dvm.Tags.run);
};

let tags = {
  let doc = "List all the tags via GitHub API";
  Cmdliner.Term.(
    app(const(Commands.tags), const()),
    Cmdliner.Term.info("tags", ~doc),
  );
};

let _ = Cmdliner.Term.eval_choice(default, [tags]) |> Cmdliner.Term.exit;
