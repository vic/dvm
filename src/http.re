module Curl = {
  let writer_callback = (a, b) => {
    Buffer.add_string(a, b);
    String.length(b);
  };

  let init_conn = (url, progress) => {
    let buffer = Buffer.create(4096);
    let connection = Curl.init();
    Curl.set_noprogress(connection, progress);
    Curl.set_post(connection, false);
    Curl.set_sslverifyhost(connection, Curl.SSLVERIFYHOST_HOSTNAME);
    Curl.set_sslverifypeer(connection, false);
    Curl.set_timeout(connection, 1200);
    Curl.set_url(connection, url);
    Curl.set_useragent(connection, "ocurl/0.9.0");
    Curl.set_verbose(connection, false);
    Curl.set_writefunction(connection, writer_callback(buffer));
    (buffer, connection);
  };

  let get = (~progress=false, url) => {
    let (buffer, connection) = init_conn(url, !progress);
    Curl.set_followlocation(connection, true);
    Curl.perform(connection);
    Curl.cleanup(connection);
    Buffer.contents(buffer);
  };
};
