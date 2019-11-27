let decorateString version = "* " ^ version

let rec rmrf path =
  match Sys.is_directory path with
  | true ->
    Sys.readdir path
    |> Array.iter (fun filename -> rmrf (Filename.concat path filename));
    Unix.rmdir path
  | false -> Sys.remove path
;;

let uname = Core.Unix.uname ()
let sysname = Core.Unix.Utsname.sysname uname
let machine = Core.Unix.Utsname.machine uname

let os =
  match sysname with
  | "Darwin" -> "osx"
  | "Linux" -> "linux"
  | _ -> failwith (sysname ^ " not supported")
;;

let arch =
  match machine with
  | "x86_64" -> "x64"
  | _ -> failwith (machine ^ " not supported")
;;
