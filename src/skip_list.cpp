#include "skip_list.h"

/**
    初始化 SkipList 对象的一些成员变量，并创建一个带有默认键和值以及指定最大层级的头节点。
*/
template<typename K, typename V>
SkipList<K, V>::SkipList(int max_level) {
    this->m_max_level = max_level;
    m_skip_list_level = 0; // 初始化当前最高索引级别
    m_element_count = 0; // 初始化节点数

    K k;
    V v;
    // 创建头节点
    m_header = new Node<K, V>(k, v, max_level);
};

/**
    关闭文件写入器和文件读取器，释放头节点的内存
*/
template<typename K, typename V>
SkipList<K, V>::~SkipList() {
    if( m_file_writer.is_open()) {
        m_file_writer.close();
    }

    if( m_file_reader.is_open()) {
        m_file_reader.close();
    }
    delete m_header;
}


template<typename K, typename V>
int SkipList<K, V>::get_random_level() {
// 该方法会随机生成 1 ~ max_level 之间的数，且：
//        1/2 的概率返回 0
//        1/4 的概率返回 1
//        1/8 的概率返回 2 以此类推
    srand((unsigned int)time(NULL)); //  使用当前时间作为随机数种子
    int level = 0;
    while( rand() % 2 && level < m_max_level) {
        ++level;
    }

    return level;
}

// 创建的跳表节点指针
template<typename K, typename V>
Node<K, V>* SkipList<K, V>::create_node(const K& key, const V& value, int level) {
    Node<K, V>* tmp_node = new Node<K, V>(key, value, level);
    return tmp_node;
}

/**
    打印跳表的每个层级及相应节点的键值对信息。
    跳表的层级从高到低打印，每个节点的格式为 (key, value)。
    
*/
template<typename K, typename V>
void SkipList<K, V>::display_list() {
    std::cout << "\n***** Skip List: *****\n";
    for(int i = m_skip_list_level; i >= 0; --i) {
        Node<K, V>* trav = m_header->forward[i];
        std::cout << "* Level " << i << ": ";
        while(trav) {
            std::cout << "    (" << trav->get_key() << ", " << trav->get_value() << ") \n";
            trav = trav->forward[i];
        }
        std::cout << '\n';
    }
}

/** 
    从最高层级开始查找，找到前一节点，然后移动到下层再开始查找，直到找到对应的节点或者到达底层。
    如果找到指定键的节点，则打印该节点的键值对信息并返回 true，否则打印错误信息并返回 false。
*/
template<typename K, typename V>
bool SkipList<K, V>::search_element(const K& key) {
    Node<K, V>* current = m_header;

    for(int i = m_skip_list_level; i >= 0; --i) {
        while(current->forward[i] && current->forward[i]->get_key() < key) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    if(current && current->get_key() == key) {
        std::cout << "Found: (Key = " << key << ", Value = " << current->get_value() << ").\n";
        return true;
    } else {
        error_handing("Not Found Key.");
        return false;
    }
}

