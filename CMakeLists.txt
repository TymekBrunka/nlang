cmake_minimum_required(VERSION 3.15)

project(nlang VERSION 1.0.0 LANGUAGES C)

# options
option(DEBUG "debug mode" ON)

include_directories("include/")
if (debug)
    add_compile_options(-D_DEBUG)
endif()

add_library(reader OBJECT "src/reader.c")
add_library(tokenizer OBJECT "src/parser/tokenizer.c")

add_library(parser OBJECT "src/parser/parser.c")
target_link_libraries(parser
    tokenizer
    reader
)

add_executable(testexe "src/main.c")
target_link_libraries(testexe
    reader
    tokenizer
)
