project(test)
cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -g -std=c++11")

include_directories(./inc ./src)
link_directories(./lib /usr/lib /usr/local/lib)

add_subdirectory(./src)
aux_source_directory(. objs)
add_executable(test ${objs})
target_link_libraries(test share_ptr -lboost_system -lboost_thread)