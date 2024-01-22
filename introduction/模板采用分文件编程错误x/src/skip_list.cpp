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

/**
    使用互斥锁保护并发操作，从最高级索引开始查找待删除节点，并记录每一层的前一节点。
    从底层开始，逐层删除指定键的节点，并更新前一节点的指针，同时检查是否需要降低索引层数。
    删除成功后打印成功信息，释放节点内存，更新元素数量，并返回 true。
    如果未找到指定键的节点，则打印错误信息并返回 false。
*/
template<typename K, typename V> 
bool SkipList<K, V>::delete_element(const K& key) {
    // 加锁
    m_mtx.lock();

    Node<K, V>* current = m_header;
    std::vector<Node<K, V>* > update(m_max_level + 1, nullptr);

    // 从最高级索引开始删
    for(int i = m_skip_list_level; i >= 0; --i) {
        while (current->forward[i] !=NULL && current->forward[i]->get_key() < key) {
            current = current->forward[i];
        }
        update[i] = current; // 记录前一节点
    }
    current = current->forward[0]; // 移动到底层
    
    if(current && current->get_key() == key) {
        // 从下往上删
        for(int i = 0; i <= m_skip_list_level; ++i) {
            if(update[i]->forward[i] != current) break;
            update[i]->forward[i] = current->forward[i];  // update[i]->forward[i]->forward[i]
        }
        
        // 检查是否需要降低索引层数
        while(m_skip_list_level > 0 && m_header->forward[m_skip_list_level] == nullptr) {
            --m_skip_list_level;
        }
        std::cout << "Successfully deleted (" << key << ", " << current->get_value() << ")" << std::endl;
        delete current;
        --m_element_count;
            
        m_mtx.unlock();

        return true;
    } 

    error_handing("Not Found Key.");
    return false;
}


/**
    使用互斥锁保护并发操作，从最高级索引开始查找插入位置，并记录每一层的前一节点。
    如果键已经存在于跳表中，则打印错误信息，解锁并返回 false。
    如果键不存在于跳表中，根据随机层数生成新节点，并逐层插入到跳表中。
    插入成功后打印成功信息，更新元素数量，并返回 true。
*/
template<typename K, typename V>
bool SkipList<K, V>::insert_element(const K& key, const V& value) {
    
    m_mtx.lock();
    Node<K, V>* current = m_header;

    std::vector<Node<K, V>* > update(m_max_level + 1, nullptr);

    // 找到插入位置
    for(int i = m_skip_list_level; i >= 0; --i) {
        while(current->forward[i] && current->forward[i]->get_key() < key) {
            current = current->forward[i];
        }
        update[i] = current;  // 记录前一节点，可能在update后面插入
    }  
    current = current->forward[0];

    // key 存在
    if(current && current->get_key() == key) {
        error_handing("Key already exists.");

        m_mtx.unlock();
        return false;
    }

    // key 不存在
    if(current == nullptr || current->get_key() != key) {
        int random_level = get_random_level();
        if(random_level > m_skip_list_level) {
            for(int i = m_skip_list_level + 1; i <= random_level; ++i) {
                update[i] = m_header;  // 新的一层索引
            }
            m_skip_list_level = random_level;
        }
        
        // 要插入的节点, level为存在于的最高层
        Node<K, V>* newNode = create_node(key, value, random_level);
        // insert node
        for(int i = 0; i <= random_level; ++i) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        std::cout << "Successfully inserted." << std::endl;
        ++m_element_count;
    }

    m_mtx.unlock();
    return true;
}

// 打印由输入参数提供的错误信息，使用 '*' 符号创建上下边界，并输出到标准输出流。
template<typename K, typename V>
void SkipList<K,V>::error_handing(const std::string& arg) {
    int len = arg.size();
    std::string cutoffLine('*', len + 5);
    std::cout << cutoffLine <<'\n';
    std::cout << arg << '\n';
    std::cout << cutoffLine <<'\n';
}

template<typename K, typename V>
const std::string SkipList<K,V>::FILE_PATH = "./dump_file";

// 打开指定路径的文件进行写入操作，遍历链表将节点的键值对写入文件，最后关闭文件。
template<typename K, typename V>
void SkipList<K, V>::dump_file() {
    std::cout << "Dumping File ...\n";
    m_file_writer.open(FILE_PATH);
    Node<K, V>* trav = m_header->forward[0];
    while(trav) {
        m_file_writer << trav->get_key() << ":" << trav->get_value() << "\n";
        trav = trav->forward[0];
    }
    m_file_writer.flush();
    m_file_writer.close();
}

// 打开指定路径的文件进行读取操作，逐行解析键值对并插入到跳表中，最后关闭文件。
template<typename K, typename V>
void SkipList<K, V>::load_file() {
    m_file_reader.open(FILE_PATH);
    std::cout << "Loading File ...\n";
    std::string line;
    std::string* key = new std::string();
    std::string* value = new std::string();
    std::cout << "File opening...\n";
    while(getline(m_file_reader, line)) {
        get_key_value_from_string(line, key, value);
        if(key->empty() || value->empty()) 
            continue;
        
        std::cout << "load (" << *key << ", " << *value << ")\n";
        insert_element(std::stoi(*key), *value);
    }
    std::cout<<"File close.\n";
    m_file_reader.close();
}


template<typename K, typename V>
int SkipList<K, V>::size() {
    return m_element_count;
}

// 从输入字符串中解析出键值对，使用指定的分隔符进行分割，并将解析结果存储在传入的 key 和 value 字符串指针中。
template<typename K, typename V>
void SkipList<K, V>::get_key_value_from_string(const std::string& str, std::string* key, std::string* value) {
    if(!is_valid_string(str)) return ;
    *key = str.substr(0, str.find(m_delimiter));
    *value = str.substr(str.find(m_delimiter) + 1, str.length());
}


template<typename K, typename V>
bool SkipList<K, V>::is_valid_string(const std::string& str) {
    if(str.empty()) return false;
    if(str.find(m_delimiter) == std::string::npos) return false;
    return true;
}