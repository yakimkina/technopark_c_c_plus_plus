cmake_minimum_required(VERSION 3.14)
project(tests_search_max_sequence)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)
#find_package(Threads REQUIRED)
#target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${SEARCH_MAX_SEQUENCE_SINGLE_THREAD_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SEARCH_MAX_SEQUENCE_SINGLE_THREAD_LIB_LIBRARIES} GTest::gtest_main)
target_include_directories(${PROJECT_NAME} PUBLIC ${SEARCH_MAX_SEQUENCE_MULTI_THREAD_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SEARCH_MAX_SEQUENCE_MULTI_THREAD_LIB_LIBRARIES} GTest::gtest_main)
