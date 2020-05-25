(lang dune 2.5)

(name dvm)

(version 1.1.0)

(generate_opam_files true)

(license Apache-2.0)

(authors "Sora Morimoto <me@bsky.moe>")

(maintainers "Sora Morimoto <me@bsky.moe>")

(source
 (github imbsky/dvm))

(bug_reports "https://github.com/imbsky/dvm/issues")

(homepage "https://github.com/imbsky/dvm")

(package
 (name dvm)
 (description "Fast and simple Deno runtime version manager written in OCaml")
 (depends
  (dune
   (>= 2.5))
  base
  cmdliner
  cohttp
  cohttp-lwt-unix
  dune-build-info
  lwt
  ocaml
  tls
  yojson))
