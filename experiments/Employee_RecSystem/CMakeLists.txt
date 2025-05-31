cmake_minimum_required(VERSION 3.26)  # CMake 3.26+ has better modules support

project(EmployeeRecSystem VERSION 1.0 LANGUAGES CXX)

# Enable C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable experimental C++ module support (for GCC/Clang)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts -Wall -Wextra")
endif()

# Add the source files
add_executable(EmployeeRecSystem
    Employee.cppm
    Employee.cpp
    EmployeeTest.cpp
)

