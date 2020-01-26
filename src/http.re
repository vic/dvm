/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
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
