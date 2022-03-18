cmake_minimum_required(VERSION 3.0.0)
project(delete_matrix)

option()

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

add_subdirectory(delete_matrix_rows_and_cols_with_zero)
#add_subdirectory(tests)

message("DELETING_MATRIX_LIB_INCLUDE_DIRS = ${DELETE_MATRIX_LIB_INCLUDE_DIRS}")
message("DELETING_MATRIX_LIB_LIBRARIES = ${DELETE_MATRIX_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${DELETE_MATRIX_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${DELETE_MATRIX_LIB_LIBRARIES})
