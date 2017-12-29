project(test)
cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -g -std=c++11")

include_directories(./src ./inc)
link_directories(/usr/lib /usr/local/lib)

aux_source_directory(. SRC)
add_subdirectory(./src)
add_executable(test ${SRC})
target_link_libraries(test -lboost_system -lboost_thread shareptr)