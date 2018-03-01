include_directories(../inc)
aux_source_directory(. SRC_SRC)
add_library(src_library ${SRC_SRC})