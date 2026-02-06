cmake_minimum_required(VERSION 3.10)
project(unit_converter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(unit_converter
    src/main.cpp
    src/CsvHandler.cpp
    src/Length.cpp
    src/Weight.cpp
)

