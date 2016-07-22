cmake_minimum_required(VERSION 3.5)
project(dnaKmers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp IO/FastQDataContainer.h IO/FastQDataContainer.cpp IO/FastQDataContainer.h Process/CounterBase.cpp Process/CounterBase.h Process/MultiThreadCounting.cpp Process/MultiThreadCounting.h)
add_executable(dnaKmers ${SOURCE_FILES})