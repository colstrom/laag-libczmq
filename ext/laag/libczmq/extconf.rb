
# -*- ruby -*-

require 'mkmf' # Ruby Standard Library

require 'laag'           # MIT License
require 'laag/libzmq'    # LGPL-3.0+ License

require_relative '../../../lib/laag/libczmq'

LAAG::BuildEnvironment.new(LAAG.libczmq).script do
  libzmq_lib     = File.join(LAAG.libzmq.install_path, 'lib')
  libzmq_include = File.join(LAAG.libzmq.install_path, 'include')

  default!(
    configure: [
      "--with-libzmq=#{LAAG.libzmq.install_path}",
      "libzmq_CFLAGS=-I#{libzmq_include}",
      "libzmq_LIBS='-L#{libzmq_lib} -lzmq'",
      '--without-docs',
    ])
end

create_makefile 'laag/libczmq'
