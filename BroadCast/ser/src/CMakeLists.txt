include_directories(../inc)
aux_source_directory(. SRC_CODE_SERVER)
add_library(server_lib ${SRC_CODE_SERVER})

