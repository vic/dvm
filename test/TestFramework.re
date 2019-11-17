let projectRoot = Sys.getcwd();

include Rely.Make({
  let config =
    Rely.TestFrameworkConfig.initialize({
      snapshotDir:
        Filename.concat(
          projectRoot,
          Filename.concat("test", "__snapshots__"),
        ),
      projectDir: projectRoot,
    });
});
