cmake_minimum_required(VERSION 3.12) 
project(calc VERSION 1.0.0 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake")
include (prevent_source_builds)
include (clang_tidy)

# list all source files except main.cpp here
add_library(${CMAKE_PROJECT_NAME} 
)

add_executable(${PROJECT_NAME} main.cpp)

# Uncomment the next line if you uncommented the add_library block
target_link_libraries(${PROJECT_NAME} ${CMAKE_PROJECT_NAME})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

file(COPY input.txt
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

