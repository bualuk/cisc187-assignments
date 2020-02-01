cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(test_cases VERSION 1.0.0 LANGUAGES CXX)

make_test(step2)
make_test(step3)
make_test(step4)
make_test(step5)
# make_test(step6)


