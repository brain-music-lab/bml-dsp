cmake_minimum_required(VERSION 3.22)

project(bml-dsp)

include(GNUInstallDirs)

add_library(bml-dsp 
    ${PROJECT_SOURCE_DIR}/src/fft.cpp
    ${PROJECT_SOURCE_DIR}/src/filter.cpp
    ${PROJECT_SOURCE_DIR}/src/realtime.cpp)

target_include_directories(bml-dsp PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(bml-dsp PRIVATE fftw3 liblsl)

# add_executable(resample-test resample-test.cpp)
add_executable(lsl-test test/lsl-test.cpp)

set(LSL_INSTALL_ROOT "/usr/local")

find_package(LSL 1.13.0 REQUIRED
      HINTS ${LSL_INSTALL_ROOT}
      "${CMAKE_CURRENT_LIST_DIR}/../../LSL/liblsl/build/"
      "${CMAKE_CURRENT_LIST_DIR}/../../LSL/liblsl/build/install"
      PATH_SUFFIXES share/LSL
)

target_link_libraries(lsl-test PRIVATE LSL::lsl)
