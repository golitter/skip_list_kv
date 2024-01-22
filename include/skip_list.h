#pragma once

#include "node.h"

#include <cstring>
#include <fstream>
#include <mutex>
#include <ctime>
#include <cstdlib>
#include <iostream>

template<typename K, typename V>
class SkipList {
private:
    int m_max_level;          // 可用最高层(最大索引级别) 
    int m_skip_list_level;    // 当前最高索引级别
    int m_element_count;      // 结点数

    Node<K, V>* m_header;     // 头节点
    
    // 文件操作
    std::ofstream m_file_writer;     
    std::ifstream m_file_reader;  

public:
    SkipList(int);
    ~SkipList();

    // 决定元素要插入到几级索引
    int get_random_level();

    // 创建结点
    Node<K, V>* create_node(const K& key, const V& value, int level);

    // 展示结点
    void display_list();
    // 按键搜索
    bool search_element(const K& key);

    // 按键删除
    bool delete_element(const K&);

    // 添加元素, 成功返回true, 失败给出错误信息并返回false
    bool insert_element(const K&, const V&);

    // 错误信息展示
    void error_handing(const std::string& content);

    void dump_file();
    void load_file();

    // 键值个数
    int size();

private:
    void get_key_value_from_string(const std::string&, std::string*, std::string*);
    bool is_valid_string(const std::string&);

public:
    // 保护多线程环境中的插入、删除等操作
    std::mutex m_mtx;
    // 键值对中键和值的分隔符
    std::string m_delimiter = ":";
};