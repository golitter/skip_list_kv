## 开发环境：

- 操作系统：Ubuntu 22.04.2 LTS on Windows 10 x86_64 
- 编译器：g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
- 编辑器：vscode
- 语言服务器：Ubuntu clangd version 14.0.0-1ubuntu1.1
- 版本控制：git 
- 项目构建：cmake 3.22.1



## 介绍

跳表（Skip List）是一种基于并联链表的数据结构，用于在有序序列中快速查找元素。跳表的设计目的是为了提供与平衡树相似的性能，但更加简单和容易实现。

跳表的核心思想是通过在不同层次上建立索引层来加速查找。每一层都是一个有序的链表，最底层包含所有元素。每一层中的节点以某种概率随机出现在更高层。这样，通过从最高层开始查找，可以快速跳过大部分无关的节点，从而在平均情况下实现对元素的快速查找。

**在平均情况下，跳表的查找、插入和删除操作都能够在$O(log n)$时间内完成。**



## 待完善

- 使用RAII智能指针
- 文件导入的泛型支持
- 文档书写











[Skip List--跳表（全网最详细的跳表文章没有之一） - 简书 (jianshu.com)](https://www.jianshu.com/p/9d8296562806)

[mhvvv/SkipList: 基于跳表实现的轻量级键值型KV存储引擎，使用C++实现。 (github.com)](https://github.com/mhvvv/SkipList)

[youngyangyang04/Skiplist-CPP: A tiny KV storage based on skiplist written in C++ language| 使用C++开发，基于跳表实现的轻量级键值数据库🔥🔥 🚀 (github.com)](https://github.com/youngyangyang04/Skiplist-CPP)