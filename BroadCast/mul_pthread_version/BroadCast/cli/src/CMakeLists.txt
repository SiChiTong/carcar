include_directories(.)
aux_source_directory(. SRC_CODE_CLI)
add_library(cli_depend ${SRC_CODE_CLI})