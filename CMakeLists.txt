cmake_minimum_required(VERSION 3.25.0)
project(DataStructWithC VERSION 1.0.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(DataStructWithC main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
