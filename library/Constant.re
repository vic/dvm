let installDir =
  Option.is_some(Sys.getenv_opt("DVM_INSTALL_DIR"))
    ? Sys.getenv("DVM_INSTALL_DIR") : Sys.getenv("HOME");

let dvmDir = Filename.concat(installDir, ".dvm");
