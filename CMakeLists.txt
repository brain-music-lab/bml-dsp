cmake_minimum_required(VERSION 3.22)

project(bml-dsp)

include(GNUInstallDirs)

add_library(bml-dsp 
    ${PROJECT_SOURCE_DIR}/src/fft.cpp
    ${PROJECT_SOURCE_DIR}/src/filter.cpp
    ${PROJECT_SOURCE_DIR}/src/realtime.cpp
    ${PROJECT_SOURCE_DIR}/src/lsl-comm.cpp)

target_include_directories(bml-dsp PRIVATE ${PROJECT_SOURCE_DIR}/include/bml-dsp)
target_include_directories(bml-dsp PUBLIC ${PROJECT_SOURCE_DIR}/include)

if (UNIX)
  find_package(LSL 1.13.0 REQUIRED
    HINTS "/usr/local"
    "${CMAKE_CURRENT_LIST_DIR}/../../LSL/liblsl/build/"
    "${CMAKE_CURRENT_LIST_DIR}/../../LSL/liblsl/build/install"
    PATH_SUFFIXES share/LSL)

  target_link_libraries(bml-dsp PRIVATE fftw3 liblsl LSL::lsl)
endif(UNIX)

if (WIN32)
    find_package(LSL 1.13.0 REQUIRED
      HINTS "C:\\Program Files (x86)\\liblsl\\lib")

    target_include_directories(bml-dsp 
    PRIVATE
      ${PROJECT_SOURCE_DIR}/vendor/fftw/include
      "C:\\Program Files (x86)\\liblsl\\include")

    find_library(FFTW3 NAMES fftw3 HINTS "${PROJECT_SOURCE_DIR}/vendor/fftw/lib")

    target_link_libraries(bml-dsp PRIVATE fftw3 liblsl)
endif(WIN32)