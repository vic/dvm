let read = path => Core_kernel.In_channel.read_all(path);

let write = (path, contents) =>
  Core_kernel.Out_channel.write_all(path, ~data=contents);

let createSymlink = Unix.link;
