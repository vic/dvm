let _ =
  Cmdliner.Term.eval_choice(
    {
      (
        Cmdliner.Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
        Cmdliner.Term.info(
          "dvm",
          ~man=[
            `S(Cmdliner.Manpage.s_bugs),
            `P(
              "Please report bugs using the issue tracker at https://github.com/imbsky/dvm/issues",
            ),
          ],
          ~exits=Cmdliner.Term.default_exits,
          ~doc="Deno Version Manager",
        ),
      );
    },
    [],
    ~argv=Sys.argv,
  )
  |> Cmdliner.Term.exit;
