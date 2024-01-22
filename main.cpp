#include <iostream>
#include "include/skip_list.hpp"

int main(int, char**){
    std::cout << "Hello, from skip_list_kv!\n";
    SkipList<int, int> skplst(6);
    skplst.insert_element(3, 4);
    skplst.display_list();
}
