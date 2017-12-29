include_directories(../inc)
aux_source_directory(. SRC_DIR)
add_library(shareptr ${SRC_DIR})