set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED YES)
set (CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -pedantic)
endif(MSVC)

include (CTest)

if(NOT EXISTS "${CMAKE_SOURCE_DIR}/extern/doctest.h")
  file(DOWNLOAD https://raw.githubusercontent.com/onqtam/doctest/2.3.4/doctest/doctest.h
    "${CMAKE_SOURCE_DIR}/../extern/doctest.h"
    STATUS DOWNLOAD_STATUS
    EXPECTED_HASH MD5=413803ccfbf0e29acbc0885028c27fe0
    )
  message(STATUS " doctest download status: ${DOWNLOAD_STATUS}")
endif()
file(MD5 "${CMAKE_SOURCE_DIR}/../extern/doctest.h" DT_HASH)
if (${DT_HASH} STREQUAL "d41d8cd98f00b204e9800998ecf8427e")
  message(NOTICE " === ")
  message(NOTICE " doctest.h is empty")
  message(NOTICE " === ")
endif()

add_library(doctest INTERFACE)
target_include_directories(doctest INTERFACE ${CMAKE_SOURCE_DIR}/../extern)

function(make_test name)
  if (${ARGC} EQUAL 1)
    add_executable(${name} ${name}.cpp) 
  else()
    add_executable(${name} ${name}.cpp ${ARGN}) 
  endif()
  if (TARGET ${CMAKE_PROJECT_NAME})
    target_link_libraries(${name} ${CMAKE_PROJECT_NAME} doctest)
  else()
    target_link_libraries(${name} doctest)
  endif()
  add_test(NAME ${name} COMMAND ${name})
endfunction()


