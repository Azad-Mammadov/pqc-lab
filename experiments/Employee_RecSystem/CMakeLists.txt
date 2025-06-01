cmake_minimum_required(VERSION 3.27)
project(EmployeeRecSystem LANGUAGES CXX)

# Set C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable modules support
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP ON)

# Employee module
add_library(employee_module
  Employee.cpp
)
target_sources(employee_module
  PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
      Employee.cppm
)
target_compile_features(employee_module PRIVATE cxx_std_20)

# Database module
add_library(database_module
  Database.cpp
)
target_sources(database_module
  PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
      Database.cppm
)
target_link_libraries(database_module
  PRIVATE
    employee_module
)
target_compile_features(database_module PRIVATE cxx_std_20)

# Executable
add_executable(database_test
  DatabaseTest.cpp
)
target_link_libraries(database_test
  PRIVATE
    database_module
)
target_compile_features(database_test PRIVATE cxx_std_20)
