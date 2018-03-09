
# -*- ruby -*-

require 'laag/library' # MIT License

module LAAG
  LIBCZMQ_GEM_ROOT = File.expand_path(File.join(__dir__, %w[.. ..]))
  LIBCZMQ_ORIGIN  = 'github.com/zeromq/czmq'
  LIBCZMQ_VERSION = (
    $LOADED_FEATURES
      .map { |f| f.match %r{/laag-libczmq-(?<version>[[:digit:]]+\.[[:digit:]]+\.[[:digit:]]+)} }
      .compact
      .map { |gem| gem['version'] }
      .uniq
      .first
  ) || (
    File
      .basename(LIBCZMQ_GEM_ROOT)
      .match(%r{^laag-libczmq-(?<version>[[:digit:]]+\.[[:digit:]]+\.[[:digit:]]+)})['version']
  )

  def self.libczmq
    @@libczmq ||= Library.new(
      gem_root: LIBCZMQ_GEM_ROOT,
      origin:   LIBCZMQ_ORIGIN,
      version:  LIBCZMQ_VERSION,
      name:     'libczmq'
    )
  end
end
