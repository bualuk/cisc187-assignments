cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(hello VERSION 1.0.0 LANGUAGES CXX)

add_library(lab1 howdy.h howdy.cpp)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} lab1)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

