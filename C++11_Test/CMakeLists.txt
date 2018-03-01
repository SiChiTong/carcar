project(test1)
cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -g -std=c++11")

include_directories(./inc ./src ./func_ptr)
set(SRC_LIB ${project_source_dir})
link_directories(${SRC_LIB}/lib)

add_subdirectory(./src)
add_subdirectory(./func_ptr)
aux_source_directory(. SRC_CODE)
add_executable(test1 ${SRC_CODE})
target_link_libraries(test1 src_library func_pointer_lib)

