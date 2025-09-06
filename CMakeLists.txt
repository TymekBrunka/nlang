cmake_minimum_required(VERSION 3.15)

project(nlang VERSION 1.0.0 LANGUAGES C)

include_directories("include/")

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
