cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(lab26 VERSION 1.0.0 LANGUAGES CXX)

# if( compare_result EQUAL 0)
#     message("The files are identical.")
# elseif( compare_result EQUAL 1)
#     message("The files are different.")
# else()
#     message("Error while comparing the files.")
# endif()

add_library(${PROJECT_NAME} 
  Person.cpp Person.h
)
add_executable(copies main.cpp)

add_custom_command(
    TARGET copies
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running $<TARGET_FILE_NAME:copies> ..."
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/copies > actual.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_test(
    NAME step4
    COMMAND ${CMAKE_COMMAND} -E compare_files
      ${CMAKE_CURRENT_SOURCE_DIR}/expected.txt actual.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(copies ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

