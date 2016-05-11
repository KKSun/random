cmake_minimum_required(VERSION 3.3)
project(random)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(src lib)

add_executable(test_multivariate_gaussian src/test_multivariate_gausian.cpp)

add_executable(test_rng src/test_rng.cpp)
