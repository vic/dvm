open Dvm

let createDownloadUrl version =
  "https://github.com/denoland/deno/releases/download/v"
  ^ version
  ^ "/deno_"
  ^ System.os
  ^ "_"
  ^ System.arch
  ^ ".gz"
;;

let run version =
  let downloadUrl = createDownloadUrl version in
  let installVersionDir = Filename.concat Constant.installDir version in
  let binaryPath = Filename.concat installVersionDir "deno" in
  if not (Sys.file_exists Constant.dvmDir)
  then Core.Unix.mkdir_p Constant.dvmDir;
  if Sys.file_exists installVersionDir
  then (
    print_endline ("Deno runtime version " ^ version ^ " is already installed.");
    exit 1);
  Core.Unix.mkdir_p installVersionDir;
  Core_kernel.Out_channel.write_all
    binaryPath
    ~data:(Rresult.R.get_ok (Http.Curl.get downloadUrl |> Ezgzip.decompress));
  Core.Unix.chmod binaryPath ~perm:755;
  print_endline
    ("Deno runtime version " ^ version ^ " was successfully installed!")
;;
