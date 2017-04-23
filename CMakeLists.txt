# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

#Compilation flags
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -pedantic")

#Project's name
project(LinkedList)

#Testing on
enable_testing()

#Subdirectories to add
add_subdirectory(src) 
add_subdirectory(test)
