cmake_minimum_required(VERSION 3.25.0)
project(DataStructWithC VERSION 1.0.0 LANGUAGES C)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  add_compile_options(-Wall)
  add_compile_options(-O0 -g)
endif()

add_subdirectory(src/)
include_directories(src/)

add_executable(DataStructWithC main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(DataStructWithC Source)