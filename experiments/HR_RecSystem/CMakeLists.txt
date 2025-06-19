cmake_minimum_required(VERSION 3.25)
project(EmployeeRecSystem VERSION 1.0)

# Enable C++23 and modules
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

# Ensure consistent runtime library settings
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add module implementation
add_library(DB_lib
    #src/Database.cpp
    #src/Database.cppm
    src/airline_ticket.cpp
    src/airline_ticket.cppm
)

# Configure module compilation for DB_lib
target_compile_options(DB_lib PRIVATE 
    $<$<CXX_COMPILER_ID:MSVC>:/experimental:module /std:c++latest>
)

# Add the test executable
add_executable(DB_test
    src/AirLine_Test.cpp
)

target_link_libraries(DB_test PRIVATE DB_lib)
target_compile_options(DB_test PRIVATE 
    $<$<CXX_COMPILER_ID:MSVC>:/experimental:module /std:c++latest>
)