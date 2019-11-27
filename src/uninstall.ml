let run version =
  let installVersionDir = Filename.concat Constant.installDir version in
  let binaryPath = Filename.concat installVersionDir "deno" in
  let currentBinaryPath = Filename.concat Constant.currentDir "deno" in
  if not (Sys.file_exists installVersionDir)
  then (
    print_endline ("Deno runtime version " ^ version ^ " does not exist.");
    exit 1);
  if Sys.file_exists currentBinaryPath
  then
    if Unix.readlink currentBinaryPath = binaryPath
    then Core.Unix.unlink currentBinaryPath;
  Helper.rmrf installVersionDir;
  print_endline ("Deno runtime version " ^ version ^ " has been uninstalled.")
;;
