module OS = struct
  type t =
    | Darwin
    | Linux
    | Win32
    | Other of string

  let uname =
    let in_channel = Unix.open_process_in "uname" in
    let uname = input_line in_channel in
    let () = close_in in_channel in
    uname

  let os_type =
    match Sys.os_type with
    | "Unix" -> (
      match uname with
      | "Darwin" -> Darwin
      | "Linux" -> Linux
      | s -> Other s )
    | "Win32" -> Win32
    | s -> Other s

  type v =
    | New
    | Old

  let version_type version =
    match version > "0.35.0" with
    | true -> New
    | false -> Old
end

module Arch = struct
  type 'a t =
    | X64
    | Other of string

  let arch_type =
    match Sys.word_size with
    | 64 -> X64
    | x -> Other (string_of_int x)
end

module FileOperation = struct
  let rec rmrf path =
    match Sys.is_directory path with
    | true ->
      Sys.readdir path
      |> Array.iter (fun filename -> rmrf (Filename.concat path filename));
      Unix.rmdir path
    | false -> Sys.remove path
end
