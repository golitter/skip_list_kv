cmake_minimum_required(VERSION 3.0.0)
project(skip_list_kv VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

# 这行代码的作用是将当前源代码目录（${CMAKE_SOURCE_DIR}）和相对路径./include添加到项目的包含目录中。
include_directories(${CMAKE_SOURCE_DIR} ./include)
add_executable(skip_list_kv main.cpp include/node.hpp include/skip_list.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
