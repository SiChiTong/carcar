project(test)
add_definitions("-Wall -g -std=c++11")
include_directories(./)
set(local_path ${project_source_dir})
link_directories(${local_path})

aux_source_directory(. SRC)
add_executable(test ${SRC})