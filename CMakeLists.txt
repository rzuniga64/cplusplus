cmake_minimum_required(VERSION 3.5)
project(cplusplus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES labs/tower_of_hanoi.cpp)
set(SOURCE_FILES labs/balanced_brackets.cpp)
set(SOURCE_FILES labs/vowel_counter.cpp)
set(SOURCE_FILES labs/bubblesort.cpp)
set(SOURCE_FILES labs/string_functions.cpp)
set(SOURCE_FILES labs/grade_average/grade_average.cpp)
set(SOURCE_FILES labs/main.cpp)
add_executable(cplusplus ${SOURCE_FILES})