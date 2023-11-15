#include <iostream>
#include "HashTable.h"
#include "IDictionary.h"
int main() {
    HashTable<int,int> table = HashTable<int,int>(100);
    std::cout << "aboba" << std::endl;
    //table.Add(Pair<int,int>(0,0));
    //table.Add(Pair<int,int>(1,1));
    //std::cout << table.Get(0) << std::endl;
    //std::cout << table.Get(1) << std::endl;
    return 0;
}