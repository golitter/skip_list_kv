#pragma once

#include <vector>

/* 定义跳表结点 */
template<typename K, typename V>
class Node {
private:
    K m_key;
    V m_value;
    int m_level;  // 索引

public:
    Node() = default;
    Node(const K& key, const V& value, int level);

    K get_key() const;
    V get_value() const;

    void set_value(const V& value);

    /**
        forward 是一个数组，其中存储了当前节点在每一层的下一个节点的指针。

    */
    std::vector<Node<K, V>* > forward;
};


// **************** 实现 *******************


template<typename K, typename V>
Node<K, V>::Node(const K& key, const V& value, int level) : m_key(key), m_value(value), m_level(level) {
    this->forward.resize(m_level + 1, nullptr);
}

template<typename K, typename V>
K Node<K, V>::get_key() const {
    return m_key;
}

template<typename K, typename V>
V Node<K, V>::get_value() const {
    return m_value;
}

template<typename K, typename V>
void Node<K, V>::set_value(const V& value) {
    this->m_value = value;
}
