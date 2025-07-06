cmake_minimum_required(VERSION 3.16)
project(Recycler VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Architecture selection
if(NOT DEFINED ARCHITECTURE)
    set(ARCHITECTURE "x64")
endif()

if(ARCHITECTURE STREQUAL "x86")
    set(CMAKE_GENERATOR_PLATFORM "Win32")
elseif(ARCHITECTURE STREQUAL "x64")
    set(CMAKE_GENERATOR_PLATFORM "x64")
else()
    message(FATAL_ERROR "Unknown architecture: ${ARCHITECTURE}")
endif()

# Set architecture-specific output base directory
set(OUTPUT_BASE_DIR ${CMAKE_SOURCE_DIR}/lib/${ARCHITECTURE})

# Define build configuration-specific output directories using generator expressions
foreach(OUTPUTCONFIG IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER "${OUTPUTCONFIG}" OUTPUTCONFIG_UPPER)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${OUTPUT_BASE_DIR}/${OUTPUTCONFIG})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${OUTPUT_BASE_DIR}/${OUTPUTCONFIG})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${OUTPUT_BASE_DIR}/${OUTPUTCONFIG})
endforeach()

# Handle single-config generators (e.g., Ninja, Makefiles)
if(NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/${CMAKE_BUILD_TYPE})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/${CMAKE_BUILD_TYPE})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/${CMAKE_BUILD_TYPE})
endif()

# Static library
add_library(Recycler STATIC Recycler.cpp Recycler.h Reusable.cpp Reusable.h)
