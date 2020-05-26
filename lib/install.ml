open Lwt.Syntax

let extension version =
  match System.OS.version_type version with
  | New -> "zip"
  | Old -> "gz"

let create_download_url version os arch =
  let path =
    match System.OS.version_type version with
    | New -> Printf.sprintf "deno-%s-%s.zip" arch os
    | Old -> Printf.sprintf "deno_%s_%s.gz" os arch
  in
  Printf.sprintf "https://github.com/denoland/deno/releases/download/v%s/%s"
    version path

let string_of_os version =
  match (System.OS.os_type, System.OS.version_type version) with
  | Darwin, New -> "apple-darwin"
  | Darwin, Old -> "osx"
  | Linux, New -> "unknown-linux-gnu"
  | Linux, Old -> "linux"
  | Win32, New -> "pc-windows-msvc"
  | Win32, Old -> "win"
  | Other os, _ -> failwith (Printf.sprintf "%s is not supported" os)

let string_of_arch version =
  match (System.Arch.arch_type, System.OS.version_type version) with
  | X64, New -> "x86_64"
  | X64, Old -> "x64"
  | Other os, _ -> failwith (Printf.sprintf "%s is not supported" os)

let command version =
  if not (Sys.file_exists Config.root_dir) then Unix.mkdir Config.root_dir 0o755;
  if not (Sys.file_exists Config.install_dir) then
    Unix.mkdir Config.install_dir 0o755;
  let url =
    create_download_url version (string_of_os version) (string_of_arch version)
  in
  let install_version_dir = Filename.concat Config.install_dir version in
  let path =
    Filename.concat install_version_dir
      (Printf.sprintf "deno.%s" (extension version))
  in
  if Sys.file_exists install_version_dir then (
    print_endline
      (Printf.sprintf "Deno runtime version %s is already installed" version);
    exit 1
  ) else
    Unix.mkdir install_version_dir 0o755;
  let target_version = Option.get (Semver.of_string version) in
  let fork_version = Option.get (Semver.of_string "0.35.0") in
  if Semver.greater_than target_version fork_version then (
    let* () = Http.get url ~path in
    let* _ =
      Lwt_process.exec ("", [| "unzip"; path; "-d"; install_version_dir |])
    in
    Unix.chmod (Filename.concat install_version_dir "deno") 0o755;
    print_endline
      (Printf.sprintf "Deno runtime version %s was successfully installed"
         version);
    Lwt.return ()
  ) else
    let* () = Http.get url ~path in
    let* _ = Lwt_process.exec ("", [| "gunzip"; path |]) in
    Unix.chmod (Filename.concat install_version_dir "deno") 0o755;
    print_endline
      (Printf.sprintf "Deno runtime version %s was successfully installed"
         version);
    Lwt.return ()
