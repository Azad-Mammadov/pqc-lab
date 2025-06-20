cmake_minimum_required(VERSION 3.10) # Specify the minimum version for CMake

project(MyProject VERSION 1.0) # Name your project and set a version

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable for your project
add_executable(MyProject string.cpp) # Replace main.cpp with your source files
