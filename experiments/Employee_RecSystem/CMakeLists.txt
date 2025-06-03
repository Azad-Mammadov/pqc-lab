cmake_minimum_required(VERSION 3.27)
project(EmployeeRecSystem LANGUAGES CXX)

# Enable C++20 modules support
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable experimental MSVC modules
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Set module paths and options
set(MSVC_MODULE_DIR "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/modules")
set(MODULE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/modules")
set(CMAKE_CXX_STANDARD_MODULES_DIR "${MODULE_OUTPUT_DIR}/std")

# Create module directories
file(MAKE_DIRECTORY "${MODULE_OUTPUT_DIR}")
file(MAKE_DIRECTORY "${CMAKE_CXX_STANDARD_MODULES_DIR}")

# Copy standard module interfaces
file(GLOB STD_MODULES "${MSVC_MODULE_DIR}/*.ixx")
file(COPY ${STD_MODULES} DESTINATION "${CMAKE_CXX_STANDARD_MODULES_DIR}")

# Enable standard modules globally
add_compile_options(/experimental:module /std:c++20 /EHsc)

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

set_target_properties(employee_module PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
    VS_GLOBAL_EnableModules "true"
    VS_GLOBAL_StandardModules "std"
    VS_GLOBAL_UseStandardPreprocessor "true"
    WINDOWS_EXPORT_ALL_SYMBOLS ON
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
target_link_libraries(database_module PUBLIC employee_module)
set_target_properties(database_module PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
    WINDOWS_EXPORT_ALL_SYMBOLS ON
)

# === EXECUTABLE ===
add_executable(database_test DatabaseTest.cpp)
target_link_libraries(database_test PRIVATE database_module)
set_target_properties(database_test PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)
