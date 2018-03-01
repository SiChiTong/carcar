include_directories(../inc)
aux_source_directory(. FUNC_PTR)
add_library(func_pointer_lib ${FUNC_PTR})