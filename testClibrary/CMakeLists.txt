project(test_c_library)
add_definitions("-Wall -g -std=c++11")
include_directories(./inc ./src)
set(PATH_LOCAL ${project_source_dir})
link_directories(${PATH_LOCAL}/lib)
message("${PATH_LOCAL}")

add_subdirectory(./src)
aux_source_directory(. TEST_CODE)
add_executable(test ${TEST_CODE})
target_link_libraries(test func_dep)

