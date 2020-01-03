// Copyright 2019-2020 BSKY
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

module Commands = {
  let init = shell => Init.run(shell);
  let install = version => Install.run(version);
  let latest = () => Latest.run();
  let ls_remote = () => Ls_remote.run();
  let ls = () => Ls.run();
  let uninstall = version => Uninstall.run(version);
  let use = version => Use.run(version);
};

let default = {
  let doc = Package_info.description;
  let man = [`S(Cmdliner.Manpage.s_bugs), `P(Package_info.issueTracker)];
  let version = Package_info.version;

  (
    Cmdliner.Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
    Cmdliner.Term.info(Package_info.name, ~doc, ~man, ~version),
  );
};

let init = {
  let doc = "Print the path to the Deno runtime.";

  Cmdliner.Term.(
    const(Commands.init)
    $ Cmdliner.Arg.(required & pos(0, some(string), None) & info([])),
    Cmdliner.Term.info("init", ~doc),
  );
};

let install = {
  let doc = "Install a specific version of the Deno runtime.";
  let argDoc = "Specify the version to install in $(docv).";
  let argDocv = "VERSION";

  Cmdliner.Term.(
    const(Commands.install)
    $ Cmdliner.Arg.(
        required
        & pos(0, some(string), None)
        & info([], ~doc=argDoc, ~docv=argDocv)
      ),
    Cmdliner.Term.info("install", ~doc),
  );
};

let latest = {
  let doc = "Install the latest version of the Deno runtime";

  Cmdliner.Term.(
    app(const(Commands.latest), const()),
    Cmdliner.Term.info("latest", ~doc),
  );
};

let ls_remote = {
  let doc = "List all remote versions of the Deno runtime.";

  Cmdliner.Term.(
    app(const(Commands.ls_remote), const()),
    Cmdliner.Term.info("ls-remote", ~doc),
  );
};

let ls = {
  let doc = "List installed versions of the Deno runtime.";

  Cmdliner.Term.(
    app(const(Commands.ls), const()),
    Cmdliner.Term.info("ls", ~doc),
  );
};

let uninstall = {
  let doc = "Uninstall a specific version of the Deno runtime.";
  let argDoc = "Specify the version to uninstall in $(docv).";
  let argDocv = "VERSION";

  Cmdliner.Term.(
    const(Commands.uninstall)
    $ Cmdliner.Arg.(
        required
        & pos(0, some(string), None)
        & info([], ~doc=argDoc, ~docv=argDocv)
      ),
    Cmdliner.Term.info("uninstall", ~doc),
  );
};

let use = {
  let doc = "Set the Deno runtime version.";
  let argDoc = "Specify the version to use in $(docv).";
  let argDocv = "VERSION";

  Cmdliner.Term.(
    const(Commands.use)
    $ Cmdliner.Arg.(
        required
        & pos(0, some(string), None)
        & info([], ~doc=argDoc, ~docv=argDocv)
      ),
    Cmdliner.Term.info("use", ~doc),
  );
};

let () =
  Cmdliner.Term.eval_choice(
    default,
    [init, install, latest, ls_remote, ls, uninstall, use],
  )
  |> Cmdliner.Term.exit;
