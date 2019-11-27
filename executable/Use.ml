open Dvm

let run version =
  let installVersionDir = Filename.concat Constant.installDir version in
  let binaryPath = Filename.concat installVersionDir "deno" in
  let currentBinaryPath = Filename.concat Constant.currentDir "deno" in
  if not (Sys.file_exists binaryPath)
  then (
    print_endline ("Deno runtime version " ^ version ^ " does not exist.");
    exit 1);
  if not (Sys.file_exists Constant.currentDir)
  then Core.Unix.mkdir_p Constant.currentDir;
  if Sys.file_exists currentBinaryPath then Sys.remove currentBinaryPath;
  Core.Unix.symlink ~target:binaryPath ~link_name:currentBinaryPath;
  print_endline ("Now using Deno runtime " ^ version)
;;
