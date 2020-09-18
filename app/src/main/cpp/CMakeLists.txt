cmake_minimum_required(VERSION 3.4.1)

aux_source_directory(bzip2 SOURCES)

add_library(
        DiffUtils
        SHARED
        native-lib.cpp
        bspatch.c
        bsdiff.c
        ${SOURCES})
include_directories(bzip2)

target_link_libraries(
        DiffUtils
        log)