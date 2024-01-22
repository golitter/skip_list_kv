#include "node.h"

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