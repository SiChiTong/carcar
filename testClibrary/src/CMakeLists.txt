include_directories(../)
aux_source_directory(. SRC_CODE)
add_library(func_dep ${SRC_CODE})