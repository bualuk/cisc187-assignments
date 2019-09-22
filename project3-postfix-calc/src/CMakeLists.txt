cmake_minimum_required(VERSION 3.1...3.14) 
if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(calc VERSION 1.0.0 LANGUAGES CXX)

# Uncomment this block if you plan to run my tests
# add_library(${CMAKE_PROJECT_NAME} 
#   Add.h Add.cpp
#   BigInt.h BigInt.cpp
#   Calc.h Calc.cpp
#   Handler.h
#  Multiply.h Multiply.cpp
#   OperandPusher.h OperandPusher.cpp
#   Power.h Power.cpp
#   util.h
# )

# List all your source files here (unless the previous block is enabled)
add_executable(${PROJECT_NAME} main.cpp)

# Uncomment the next line if you uncommented the add_library block
# target_link_libraries(${PROJECT_NAME} ${CMAKE_PROJECT_NAME})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

file(COPY input.txt
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
