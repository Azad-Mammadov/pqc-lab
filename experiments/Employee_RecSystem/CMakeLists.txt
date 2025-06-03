cmake_minimum_required(VERSION 3.27)
project(EmployeeRecSystem LANGUAGES CXX)

# Enable C++20 modules support with experimental features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable experimental MSVC modules
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Set paths for module interfaces
set(MSVC_MODULE_DIR "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/modules")
set(MODULE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/modules")

# Create module directories
file(MAKE_DIRECTORY "${MODULE_OUTPUT_DIR}")

# === EMPLOYEE MODULE ===
add_library(employee_module)
target_sources(employee_module
    PUBLIC
        FILE_SET CXX_MODULES 
        BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}"
        FILES Employee.cppm
    PRIVATE
        Employee.cpp
)
target_include_directories(employee_module
    PUBLIC
        "${MSVC_MODULE_DIR}"
)
target_compile_features(employee_module PUBLIC cxx_std_20)
set_target_properties(employee_module PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)

# === DATABASE MODULE ===
add_library(database_module)
target_sources(database_module
    PUBLIC
        FILE_SET CXX_MODULES FILES
        Database.cppm
    PRIVATE
        Database.cpp
)
target_link_libraries(database_module PRIVATE employee_module)
target_compile_features(database_module PRIVATE cxx_std_20)
set_target_properties(database_module PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)

# === EXECUTABLE ===
add_executable(database_test DatabaseTest.cpp)
target_link_libraries(database_test PRIVATE database_module)
target_compile_features(database_test PRIVATE cxx_std_20)
set_target_properties(database_test PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)
