cmake_minimum_required(VERSION 3.12) # Ensure you have a version of CMake that supports the required C++ standard

project(EmployeeRecSystem VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add your source files
add_executable(EmployeeRecSystem experiments/Employee_RecSystem/Employee.cppm)

# Optionally, you can set compiler-specific flags if needed
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Using GCC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Using Clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Using Visual Studio
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()
