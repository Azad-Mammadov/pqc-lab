cmake_minimum_required(VERSION 3.27)
#set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
project(EmployeeRecSystem LANGUAGES CXX)

set(CMAKE_CXX_SCAN_FOR_MODULES OFF CACHE BOOL "Disable module scanning" FORCE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

       #set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API ON)
       #set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP ON)

# Path to your precompiled std modules interface files (.ifc)
set(STD_IFC_PATH "C:/stdmodules")

# If using Clang on Windows (custom path)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Override compiler path to your specific clang-cl.exe
    # Adjust this path if your clang executable is named differently or located elsewhere
    set(CMAKE_CXX_COMPILER "C:/clang/clang+llvm-20.1.6-x86_64-pc-windows-msvc/bin/clang-cl.exe" CACHE STRING "" FORCE)

    # Clang flags to search for module interfaces (example)
    # Clang uses -fmodule-map-file= and -fprebuilt-module-path= but MSVC modules are different,
    # so you might need to experiment or adapt.
    # Here's an example to add the std module search path:
    add_compile_options(
        -fprebuilt-module-path=${STD_IFC_PATH}
        -fmodules-ts
    )
endif()

# === EMPLOYEE MODULE ===
add_library(employee_module
  Employee.cpp
)
target_sources(employee_module
  PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
      Employee.cppm
)
target_compile_features(employee_module PRIVATE cxx_std_20)

target_compile_options(employee_module PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/ifcSearchDir${STD_IFC_PATH}>
  $<$<CXX_COMPILER_ID:Clang>:-fprebuilt-module-path=${STD_IFC_PATH} -fmodules-ts>
)

# === DATABASE MODULE ===
add_library(database_module
  Database.cpp
)
target_sources(database_module
  PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
      Database.cppm
)
target_link_libraries(database_module PRIVATE employee_module)
target_compile_features(database_module PRIVATE cxx_std_20)

target_compile_options(database_module PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/ifcSearchDir${STD_IFC_PATH}>
  $<$<CXX_COMPILER_ID:Clang>:-fprebuilt-module-path=${STD_IFC_PATH} -fmodules-ts>
)

# === EXECUTABLE ===
add_executable(database_test
  DatabaseTest.cpp
)
target_link_libraries(database_test PRIVATE database_module)
target_compile_features(database_test PRIVATE cxx_std_20)

target_compile_options(database_test PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/ifcSearchDir${STD_IFC_PATH}>
  $<$<CXX_COMPILER_ID:Clang>:-fprebuilt-module-path=${STD_IFC_PATH} -fmodules-ts>
)
