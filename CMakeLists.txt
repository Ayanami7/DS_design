cmake_minimum_required(VERSION 3.10)
project(BST_MaxNum)

set(CMAKE_CXX_STANDARD 17)

set(publish_bin_release ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	${publish_bin_release})

aux_source_directory(./src SOURCES)
add_executable(BST_MaxNum ${SOURCES})

