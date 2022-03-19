cmake_minimum_required(VERSION 3.0.0)
project(delete_matrix)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror")

option(TEST_MODE OFF)
option(FBINFER OFF)
option(SANITIZERS OFF)

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

add_subdirectory(delete_matrix_rows_and_cols_with_zero)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${DELETE_MATRIX_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${DELETE_MATRIX_LIB_LIBRARIES})

if (TEST_MODE)
	add_subdirectory(tests)
endif(TEST_MODE)

