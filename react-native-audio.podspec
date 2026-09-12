require 'json'

package = JSON.parse(File.read(File.join(__dir__, 'package.json')))

Pod::Spec.new do |spec|
  spec.name         = package['name']
  spec.version      = package['version']
  spec.summary      = 'Native audio playback for React Native.'
  spec.description  = 'A TurboModule-based native audio playback package for React Native.'
  spec.homepage     = 'https://github.com/your-org/react-native-audio'
  spec.license      = { :type => 'MIT' }
  spec.author       = { 'react-native-audio' => 'maintainers' }
  spec.source       = { :path => '.' }
  spec.platforms     = { :ios => '13.0' }
  spec.requires_arc = true

  spec.source_files = 'ios/**/*.{h,mm}', 'shared/**/*.{h,cc,cpp}'
  spec.public_header_files = 'ios/**/*.h', 'shared/**/*.h'
  spec.header_mappings_dir = 'shared'
  spec.pod_target_xcconfig = {
    'HEADER_SEARCH_PATHS' => '$(PODS_TARGET_SRCROOT)/shared'
  }

  spec.dependency 'React-Core'
  spec.dependency 'React-Codegen'
  spec.dependency 'ReactCommon/turbomodule/core'
end