cmake_minimum_required(VERSION 3.0.0)
project(search_max_sequence)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

option(TEST_MODE OFF)
option(FBINFER OFF)
option(SANITIZERS OFF)

#find_package(Threads)

if (TEST_MODE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage -fPIC")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
endif(TEST_MODE)

if (FBINFER)
	set(CMAKE_C_COMPILER "infer run -- ${CMAKE_C_COMPILER}")
endif(FBINFER)

if (SANITIZERS)
	add_compile_options(-fno-sanitize-recover=all -fsanitize-undefined-trap-on-error -fsanitize=$(SANITIZERS))
endif(SANITIZERS)

add_subdirectory(search_max_sequence_single_thread)
add_subdirectory(search_max_sequence_multiple_threads)

find_package(Threads REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC Threads::Threads)

add_executable(${PROJECT_NAME} main.c)

#target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(${PROJECT_NAME} PUBLIC ${SEARCH_MAX_SEQUENCE_SINGLE_THREAD_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SEARCH_MAX_SEQUENCE_SINGLE_THREAD_LIB_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SEARCH_MAX_SEQUENCE_MULTI_THREAD_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SEARCH_MAX_SEQUENCE_MULTI_THREAD_LIB_LIBRARIES})

if (TEST_MODE)
	add_subdirectory(tests)
endif(TEST_MODE)
