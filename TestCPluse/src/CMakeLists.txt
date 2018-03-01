include_directories(../inc)
aux_source_directory(. SRC_DEP)
add_library(dep ${SRC_DEP})