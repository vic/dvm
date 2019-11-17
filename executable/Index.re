let version = Dvm.Package_Info.version;

let doc = "Deno Version Manager";

let exits = Cmdliner.Term.default_exits;

let man = [
  `S(Cmdliner.Manpage.s_bugs),
  `P(
    "Please report bugs using the issue tracker at https://github.com/imbsky/dvm/issues",
  ),
];

let _ =
  Cmdliner.Term.eval_choice(
    {
      (
        Cmdliner.Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
        Cmdliner.Term.info("dvm", ~doc, ~exits, ~man, ~version),
      );
    },
    [],
    ~argv=Sys.argv,
  )
  |> Cmdliner.Term.exit;
