cmake_minimum_required(VERSION 3.1...3.14) 
if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(calc VERSION 1.0.0 LANGUAGES CXX)

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

