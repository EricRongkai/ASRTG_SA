cmake_minimum_required(VERSION 3.4...3.18)

project(DSPLIB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g") 
set(CMAKE_BUILD_TYPE "Release") 
set(PYBIND11_CPP_STANDARD -std=c++11)

add_subdirectory(pybind11)

file(GLOB CPP_FILE_LIST "src/*.cpp")

message("SRC LIST: ${CPP_FILE_LIST}")

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include/simulink_include ${CMAKE_SOURCE_DIR}/pybind11/include/pybind11)

pybind11_add_module(DSP_Fun DSP_Fun.cpp ${CPP_FILE_LIST})

find_package(pybind11 REQUIRED)

add_library(DSPTest SHARED DSP_Fun.cpp ${CPP_FILE_LIST})

target_link_libraries(DSPTest pybind11::module)




