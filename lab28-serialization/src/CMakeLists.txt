cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(lab28 VERSION 1.0.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} 
  lab28.cpp lab28.h
  cgi.cpp cgi.h
  util.cpp util.h
)

add_executable(calc main.cpp
)

target_link_libraries(${PROJECT_NAME} json)
target_link_libraries(calc ${PROJECT_NAME} json)
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

