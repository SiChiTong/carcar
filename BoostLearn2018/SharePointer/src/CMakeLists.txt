aux_source_directory(. objs_share_ptr)
include_directories(../inc)
add_library(share_ptr ${objs_share_ptr})