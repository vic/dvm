let version = Dvm.Package_Info.version;

let doc = "Fast and simple Deno version manager, built-in Native Reason.";

let man = [
  `S(Cmdliner.Manpage.s_bugs),
  `P(
    "Please report bugs using the issue tracker at https://github.com/imbsky/dvm/issues",
  ),
];

let baseCommand = {
  (
    Cmdliner.Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
    Cmdliner.Term.info("dvm", ~doc, ~man, ~version),
  );
};

let _ = Cmdliner.Term.eval_choice(baseCommand, []) |> Cmdliner.Term.exit;
