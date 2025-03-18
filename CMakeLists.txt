## \brief CMake configuration file for project setup.
## \author Konstantin Growitsch and Maximilian Tezacki
## \17.03.2025 2025

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.31.3)

## \brief Define the project name and version
project(Project VERSION 1.0)

## \brief Collect all .c source files from the 'code' directory
# This searches for all .c files in the specified directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/code/*.c")

## \brief Ensure source files were found, otherwise terminate with an error
if(NOT SOURCES)
    message(FATAL_ERROR "No .c files found in the 'code' directory!")
endif()

## \brief Create an executable target from the collected source files
# The executable will be named 'MyExecutable'
add_executable(MyExecutable ${SOURCES})

## \brief Set compiler options depending on the compiler being used
if(MSVC)
    ## \note For MSVC, use /W4 to enable the highest warning level
    target_compile_options(MyExecutable PRIVATE /W4)
else()
    ## \note For GCC and Clang, enable additional warnings and pedantic mode
    target_compile_options(MyExecutable PRIVATE -Wall -Wextra -pedantic)
endif()

## \brief Specify the directory containing header files
# This allows the compiler to find header files located in the 'header' directory
target_include_directories(MyExecutable PRIVATE ${PROJECT_SOURCE_DIR}/header)

