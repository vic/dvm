let version = Dvm.Package_Info.version;

let doc = "Fast and simple Deno version manager, built-in Native Reason.";

let exits = Cmdliner.Term.default_exits;

let man = [
  `S(Cmdliner.Manpage.s_bugs),
  `P(
    "Please report bugs using the issue tracker at https://github.com/imbsky/dvm/issues",
  ),
];

let sdocs = Cmdliner.Manpage.s_common_options;

let baseCommand = {
  (
    Cmdliner.Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
    Cmdliner.Term.info("dvm", ~doc, ~exits, ~man, ~sdocs, ~version),
  );
};

let _ =
  Cmdliner.Term.eval_choice(baseCommand, [], ~argv=Sys.argv)
  |> Cmdliner.Term.exit;
