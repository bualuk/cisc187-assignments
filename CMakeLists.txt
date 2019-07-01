cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(cisc187 VERSION 1.0.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD_REQUIRED 11)

include (CTest)

if(NOT EXISTS "${CMAKE_SOURCE_DIR}/extern/doctest.h")
  file(DOWNLOAD https://raw.githubusercontent.com/onqtam/doctest/2.3.3/doctest/doctest.h
    "${CMAKE_SOURCE_DIR}/extern/doctest.h"
    STATUS DOWNLOAD_STATUS
    EXPECTED_HASH MD5=f37c2fdc39c7d8eb7d2dbf7a039a37df
    )
  list (GET DOWNLOAD_STATUS 0 status)
  if (NOT ${status})
    message(NOTICE " === ")
    message(NOTICE " doctest download status: ${DOWNLOAD_STATUS}")
    message(NOTICE " === ")
  endif()
endif()
file(MD5 "${CMAKE_SOURCE_DIR}/extern/doctest.h" DT_HASH)
if (${DT_HASH} STREQUAL "d41d8cd98f00b204e9800998ecf8427e")
  message(NOTICE " === ")
  message(NOTICE " doctest.h is empty")
  message(NOTICE " === ")
endif()

add_library(doctest INTERFACE)
target_include_directories(doctest INTERFACE ${CMAKE_SOURCE_DIR}/extern)

add_subdirectory(lab01)
# add_subdirectory(lab02)
# add_subdirectory(lab03)

