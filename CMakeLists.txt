cmake_minimum_required(VERSION 3.0.0)
project(skip_list_kv VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(skip_list_kv main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
