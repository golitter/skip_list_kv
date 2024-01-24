#include <iostream>
#include "include/skip_list.hpp"

// 测试插入、删除、搜索、展示和导出
void TEST_f() {
        std::cout << "Hello, from skip_list_kv!\n";
    SkipList<int, int> skplst(6);
    skplst.insert_element(3, 4);
    skplst.insert_element(4, 3);
    skplst.insert_element(45, 33);
    skplst.display_list();
    
    if(skplst.delete_element(3)) {
        std::cout<<"Delete key = 3 is OK!\n";
    }
    skplst.display_list();

    if(skplst.search_element(3)) {
        std::cout<<"Search key = 3 is OK!\n";
    }
    if(skplst.search_element(45)) {
        std::cout<<"Search key = 45 is OK!\n";
    }
    skplst.dump_file();
}

// 测试导入
//TODO: 键值对的读取等，只能为 (K: int, V: string) 型，需要修改
void TEST_s() {
    SkipList<int, std::string> tskl(7);
    tskl.load_file();
    tskl.display_list();
}
int main(int, char**){

    // 测试1
    TEST_f();

    // 测试2
    TEST_s();

    return 0;
}
