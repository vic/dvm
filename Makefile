build:
	dune build

fmt:
	dune build @fmt --auto-promote

fmt-check:
	dune build @fmt

dvm:
	dune build @install
