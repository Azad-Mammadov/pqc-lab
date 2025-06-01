cmake_minimum_required(VERSION 3.26)

# Force Clang compiler before project declaration
set(CMAKE_CXX_COMPILER "C:/clang/clang+llvm-20.1.6-x86_64-pc-windows-msvc/bin/clang++.exe" 
    CACHE STRING "Clang compiler path" FORCE)

# Project settings
project(EmployeeRecSystem VERSION 1.0 LANGUAGES CXX)

# C++20 settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create module cache directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/pcm)

# Set module compilation flags directly
add_compile_options(
    -fmodules
    -fbuiltin-module-map
    -fimplicit-module-maps
    -fmodules-cache-path=${CMAKE_BINARY_DIR}/pcm
)

# Define module interfaces
add_library(employee_module OBJECT Employee.cppm)
target_compile_options(employee_module PRIVATE
    -fmodule-name=employee
)

add_library(database_module OBJECT Database.cppm)
target_compile_options(database_module PRIVATE
    -fmodule-name=database
)

# Set properties for both modules
foreach(module employee_module database_module)
    set_target_properties(${module} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE ON
    )
endforeach()

# Main executable
add_executable(EmployeeRecSystem
    Employee.cpp
    Database.cpp
    DatabaseTest.cpp
)

# Add module dependencies
add_dependencies(EmployeeRecSystem employee_module database_module)
target_link_libraries(EmployeeRecSystem PRIVATE employee_module database_module)
