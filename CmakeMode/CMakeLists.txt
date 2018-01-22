project(test)
cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -g -std=c++11")

include_directories(./src ./inc)
link_directories(/usr/lib /usr/local/lib ${project_source_dir}/lib)

aux_source_directory(. SRC)
add_subdirectory(./src)
add_subdirectory(./add)

add_executable(test ${SRC})
target_link_libraries(test -lboost_system -lboost_thread shareptr)

message("********${project_source_dir}********")
message("########${CMAKE_CURRENT_SOURCE_DIR}##########")
set(DIR ${project_source_dir})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++11")