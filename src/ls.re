let decorateString = version =>
  <Pastel> <Pastel color=Pastel.Cyan> "* " </Pastel> version </Pastel>;

let run = () => {
  if (!Sys.file_exists(Constant.installDir)) {
    Core.Unix.mkdir_p(Constant.installDir);
  };

  Core.Sys.ls_dir(Constant.installDir)
  |> List.rev
  |> List.iter(version => version |> decorateString |> Console.log);
};
