include_directories(../inc ../src)
aux_source_directory(. SRC_SMART_PTR)
add_library(smart_ptr ${SRC_SMART_PTR})