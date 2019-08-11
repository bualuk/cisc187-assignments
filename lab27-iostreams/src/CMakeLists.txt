cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(lab27 VERSION 1.0.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} 
  point.cpp point.h
)
add_executable(fstream main.cpp)

add_custom_command(
    TARGET fstream
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running $<TARGET_FILE_NAME:fstream> ..."
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/fstream -o out.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_test(
    NAME step7
    COMMAND ${CMAKE_COMMAND} -E compare_files
      mydata.txt out.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(fstream ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

file(COPY mydata.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

