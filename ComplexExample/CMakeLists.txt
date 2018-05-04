cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(complexExample)
add_executable(complexExample
  complexMain.cpp
  Complex.h
  Complex.cpp
)