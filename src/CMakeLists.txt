cmake_minimum_required(VERSION 3.25.0)

project(Source VERSION 1.0.0 LANGUAGES C)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  add_compile_options(-Wall)
  add_compile_options(-O0 -g)
endif()

file(GLOB SOURCES "*.c" "*.h")

add_library(Source
  ${SOURCES}
)