cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(lab11 VERSION 1.0.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} 
  ${PROJECT_NAME}.h ${PROJECT_NAME}.cpp
)
add_executable(main main.cpp)

target_link_libraries(main ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

