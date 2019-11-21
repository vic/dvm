/*
 Copyright 2019 DVM contributors
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
     http://www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

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
  let ls_remote = () => Ls_remote.run();
  let ls = () => Ls.run();
  let uninstall = version => Uninstall.run(version);
  let use = version => Use.run(version);
};

let init = {
  Cmdliner.Term.(
    const(Commands.init)
    $ Cmdliner.Arg.(required & pos(0, some(string), None) & info([])),
    Cmdliner.Term.info("init", ~doc="Print the path to a Deno runtime."),
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

let ls_remote = {
  Cmdliner.Term.(
    app(const(Commands.ls_remote), const()),
    Cmdliner.Term.info(
      "ls-remote",
      ~doc="List all remote versions of a Deno runtime.",
    ),
  );
};

let ls = {
  Cmdliner.Term.(
    app(const(Commands.ls), const()),
    Cmdliner.Term.info(
      "ls",
      ~doc="List installed versions of a Deno runtime.",
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
    Cmdliner.Term.info("use", ~doc="Set the Deno runtime version."),
  );
};

let _ =
  Cmdliner.Term.eval_choice(
    default,
    [init, install, ls_remote, ls, uninstall, use],
  )
  |> Cmdliner.Term.exit;
