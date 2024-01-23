#!/bin/bash

# 编译 insert_test.cpp
g++ -std=c++11 -I./include stress_test/insert_test.cpp -o insert_test

# 运行压力测试
./insert_test

# 删除编译生成的可执行文件
rm insert_test
