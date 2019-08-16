cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(lab28 VERSION 1.0.0 LANGUAGES CXX)
include ("../common.cmake")


if(NOT EXISTS "${CMAKE_SOURCE_DIR}/../extern/json.hpp")
  file(DOWNLOAD https://github.com/nlohmann/json/releases/download/v3.7.0/json.hpp
    "${CMAKE_SOURCE_DIR}/../extern/json.hpp"
    STATUS DOWNLOAD_STATUS
    EXPECTED_HASH MD5=3a33df05082ae70e663f19477c63b13e
    )
  message(STATUS " json download status: ${DOWNLOAD_STATUS}")
endif()
file(MD5 "${CMAKE_SOURCE_DIR}/../extern/json.hpp" DT_HASH)
if (${DT_HASH} STREQUAL "d41d8cd98f00b204e9800998ecf8427e")
  message(NOTICE " === ")
  message(NOTICE " json.hpp is empty")
  message(NOTICE " === ")
endif()

add_library(json INTERFACE)
target_include_directories(json INTERFACE ${CMAKE_SOURCE_DIR}/../extern)

add_subdirectory(src)
add_subdirectory(test)

