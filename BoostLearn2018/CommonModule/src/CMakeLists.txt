include_directories(../inc)
aux_source_directory(. SRC_CODE_DEPEND)
add_library(test_depend ${SRC_CODE_DEPEND})


