cmake_minimum_required(VERSION 3.25.0)

project(Source VERSION 1.0.0 LANGUAGES C)

file(GLOB SOURCES "*.c" "*.h")

add_library(Source
  ${SOURCES}
)