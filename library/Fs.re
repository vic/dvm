let write = (path, contents) =>
  Core_kernel.Out_channel.write_all(path, ~data=contents);
