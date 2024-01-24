#!/bin/bash

# 任何命令返回非零退出码时立即停止执行，并输出相应的错误信息
set -e


# 运行压力测试 并将结果输入到insert_test_result.txt 文件内

echo -e "\n" > insert_test_result.txt

# 10万

g++ -std=c++11 -I./include insert_test_100000.cpp -o insert_test_100000
# 运行可执行文件
./insert_test_100000 >> insert_test_result.txt
echo -e "\n" >> insert_test_result.txt
# 删除编译生成的可执行文件
rm insert_test_100000

# 20万

g++ -std=c++11 -I./include insert_test_200000.cpp -o insert_test_200000
# 运行可执行文件
./insert_test_200000 >> insert_test_result.txt
echo -e "\n" >> insert_test_result.txt
# 删除编译生成的可执行文件
rm insert_test_200000

# 50万

g++ -std=c++11 -I./include insert_test_500000.cpp -o insert_test_500000
# 运行可执行文件
./insert_test_500000 >> insert_test_result.txt
echo -e "\n" >> insert_test_result.txt
# 删除编译生成的可执行文件
rm insert_test_500000

