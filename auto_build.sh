#!/bin/bash

# 任何命令返回非零退出码时立即停止执行，并输出相应的错误信息
set -e

mkdir -p build
cd build

# 生成MakeFile文件
cmake ..

# 构建可执行文件
make -j8

# 执行可执行文件
./skip_list_kv

# 退回到原来目录下
cd ..

