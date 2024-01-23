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

## 项目文件

- `main.cpp`    用调表进行数据操作
- `build`    cmake构建目录
- `include`    跳表及其结点的实现
- `introduction`    项目讲解及备份等非项目必要内容
- `stress_test`    压力测试的cpp文件
- `CMakeLists.txt`    cmake配置文件
- `auto_build.sh`    自动运行cmake配置文件并在终端输出main.cpp内容
- `run_stress_test_about_insert.sh`    自动运行插入测试并重定向到文件内`insert_test_result.txt`
- `insert_test_result.txt`    插入测试结果 

## 提供接口

- 插入结点

```cpp
    bool insert_element(const K& key, const V& value);
```

- 删除结点

```cpp
    bool delete_element(const K& key);
```

- 查询结点

```cpp
    bool search_element(const K& key);
```

- 展示跳表

```cpp
    void display_list();
```

- 数据存盘

```cpp
    void dump_file();
```

- 数据加载

```cpp
    void load_file();
```

- 数据大小

```cpp
    int size();
```



## 测试表现

调表树高：18

采用随机插入数据测试：

| 插入数据规模（万条） | 耗时（秒） | 每秒处理 |
| -------------------- | ---------- | -------- |
| 10                   | 0.78066    | 128095   |
| 20                   | 1.90948    | 104741   |
| 50                   | 8.11153    | 61640.6  |

![image-20240123121801494](README.assets/image-20240123121801494.png)

## 待完善

- 文件导入的泛型支持
- 文档书写











[Skip List--跳表（全网最详细的跳表文章没有之一） - 简书 (jianshu.com)](https://www.jianshu.com/p/9d8296562806)

[mhvvv/SkipList: 基于跳表实现的轻量级键值型KV存储引擎，使用C++实现。 (github.com)](https://github.com/mhvvv/SkipList)

[youngyangyang04/Skiplist-CPP: A tiny KV storage based on skiplist written in C++ language| 使用C++开发，基于跳表实现的轻量级键值数据库🔥🔥 🚀 (github.com)](https://github.com/youngyangyang04/Skiplist-CPP)