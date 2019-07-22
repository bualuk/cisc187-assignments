cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(lab13 VERSION 1.0.0 LANGUAGES CXX)
include ("../common.cmake")

add_subdirectory(test)

