cmake_minimum_required(VERSION 3.5)
project(cplusplus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tower_of_hanoi.cpp)
set(SOURCE_FILES balanced_brackets.cpp)
set(SOURCE_FILES vowel_counter.cpp)
set(SOURCE_FILES bubblesort.cpp)
set(SOURCE_FILES string_functions.cpp)
set(SOURCE_FILES grade_average.cpp)
add_executable(cplusplus ${SOURCE_FILES})