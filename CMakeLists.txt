cmake_minimum_required(VERSION 3.22)

project(bml-dsp)

include(GNUInstallDirs)

add_library(bml-dsp 
    ${PROJECT_SOURCE_DIR}/src/fft.cpp
    ${PROJECT_SOURCE_DIR}/src/filter.cpp
    ${PROJECT_SOURCE_DIR}/src/realtime.cpp)

target_include_directories(bml-dsp PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(bml-dsp PRIVATE fftw3)

# add_executable(resample-test resample-test.cpp)
