set (CMAKE_CXX_STANDARD_REQUIRED 11)

include (CTest)

if(NOT EXISTS "${CMAKE_SOURCE_DIR}/extern/doctest.h")
  file(DOWNLOAD https://raw.githubusercontent.com/onqtam/doctest/2.3.3/doctest/doctest.h
    "${CMAKE_SOURCE_DIR}/../extern/doctest.h"
    STATUS DOWNLOAD_STATUS
    EXPECTED_HASH MD5=f37c2fdc39c7d8eb7d2dbf7a039a37df
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
  target_link_libraries(${name} ${CMAKE_PROJECT_NAME} doctest)
  add_test(NAME ${name} COMMAND ${name})
endfunction()


