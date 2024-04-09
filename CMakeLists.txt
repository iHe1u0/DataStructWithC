cmake_minimum_required(VERSION 3.25.0)
project(DataStructWithC VERSION 1.0.0 LANGUAGES C)

# 设置编译器选项,解决中文乱码
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
  if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    message("Windows gcc compile...")
    add_compile_options(-fexec-charset=GBK)
    add_compile_options(-Wall)
    add_compile_options(-O0)
  endif()
  if(MSVC)
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:gbk>")
  endif()
endif()

add_subdirectory(src/)
include_directories(src/)

add_executable(DataStructWithC main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(DataStructWithC Source)