project(test_c_library)
add_definitions("-Wall -g -std=c++11")
include_directories(./inc ./src ./smart_ptr)
set(PATH_LOCAL ${project_source_dir})
link_directories(${PATH_LOCAL}/lib)
message("${PATH_LOCAL}")

add_subdirectory(./src )
add_subdirectory(./smart_ptr)

aux_source_directory(. TEST_CODE)
add_executable(test ${TEST_CODE})
target_link_libraries(test func_dep smart_ptr)

