module Install = {
  let createDownloadUrl = version =>
    "https://github.com/denoland/deno/releases/download/v"
    ++ version
    ++ "/"
    ++ "deno"
    ++ "_"
    ++ System.os
    ++ "_"
    ++ System.arch
    ++ ".gz";
};
