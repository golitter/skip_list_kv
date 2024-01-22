cmake_minimum_required(VERSION 3.0.0)
project(skip_list_kv VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# 这行代码的作用是将当前源代码目录（${CMAKE_SOURCE_DIR}）和相对路径./include添加到项目的包含目录中。
include_directories(${CMAKE_SOURCE_DIR} ./include)
# 添加可执行文件TEST，它由main.cpp、Gun.cpp和Soldier.cpp这三个源文件构建而成。
add_executable(skip_list_kv main.cpp src/skip_list.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
