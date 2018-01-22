project(test)
cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -g -std=c++11")

include_directories(./inc ./src)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
message("***********${CMAKE_CURRENT_SOURCE_DIR}*************")
message("#################${PROJECT_SOURCE_DIR}########################")
aux_source_directory(. SRC_CODE)
add_subdirectory(./src)
add_executable(test ${SRC_CODE})
target_link_libraries(test test_depend -lboost_system -lboost_thread)

