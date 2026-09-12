cmake_minimum_required(VERSION 3.13)

project(react_native_audio)

include(${REACT_ANDROID_DIR}/cmake-utils/ReactNative-application.cmake)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
  ../../../../shared/NativeAudioModule.cc
  ../../../../shared/soundEngine.cc
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ../../../../shared)

target_link_libraries(${CMAKE_PROJECT_NAME}
  android
  log
  mediandk
)
