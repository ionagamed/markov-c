cmake_minimum_required(VERSION 3.6)
project(markov_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MarkovTextGenerator.cpp MarkovTextGenerator.h util.cpp util.h DequeHash.h)
add_executable(markov_c ${SOURCE_FILES})