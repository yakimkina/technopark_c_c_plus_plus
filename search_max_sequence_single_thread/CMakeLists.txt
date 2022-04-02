cmake_minimum_required(VERSION 3.0.0)
project(search_max_sequence_single_thread_lib)

file(GLOB SOURCES *.c search_max_sequence_implementation/*.c)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB INCLUDE_DIRS "${INCLUDE_DIRS} search_max_sequence_implementation")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

#include_directories(${CMAKE_SOURCE_DIR}/search_max_sequence_implementation)

set(SEARCH_MAX_SEQUENCE_SINGLE_THREAD_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(SEARCH_MAX_SEQUENCE_SINGLE_THREAD_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
