
# -*- ruby -*-

Gem::Specification.new do |spec|
  tag     = %x{git describe --tags --abbrev=0}.chomp
  commits = %x{git rev-list --count #{tag}..HEAD}.chomp

  spec.name          = "laag-libczmq"
  spec.version       = "#{tag}.#{commits}"
  spec.authors       = ["Chris Olstrom"]
  spec.email         = ["chris@olstrom.com"]
  spec.summary       = "Library as a Gem - libczmq"
  spec.homepage      = "https://github.com/colstrom/laag-libczmq"
  spec.licenses      = ['MPL-2.0']
  spec.files         = `git ls-files -z`.split("\x0")
  spec.require_paths = ["lib"]
  spec.extensions    = ["ext/laag/libczmq/extconf.rb"]

  spec.add_runtime_dependency 'laag',        '~> 0.5', '>= 0.5.0'
  spec.add_runtime_dependency 'laag-libzmq', '~> 4.2', '>= 4.2.3'
end
