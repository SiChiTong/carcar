project(test)
cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -g -std=c++11")

include_directories(./ ./src)
set(LOCAL ${project_source_dir})
link_directories(${LOCAL}/lib)

add_subdirectory(./src)
aux_source_directory(. SRC)
add_executable(test ${SRC})
target_link_libraries(test )




