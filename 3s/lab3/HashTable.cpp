#include <iostream>
#include "HashTable.h"
#include "IDictionary.h"
int main() {
    HashTable<int,int> table = HashTable<int,int>(100);
    std::cout << "aboba" << std::endl;
    table.Add(Pair<int,int>(0,128));
    table.Add(Pair<int,int>(1,256));
    table.Add(Pair<int,int>(2,-1));
    table.Add(Pair<int,int>(3,0));
    table.Add(Pair<int,int>(4,512));
    table.Add(Pair<int,int>(5,1024));
    table.Add(Pair<int,int>(6,-32));
    table.Add(Pair<int,int>(7,-64));
    std::cout << table.Get(0) << std::endl;
    std::cout << table.Get(1) << std::endl;
    std::cout << table.Get(2) << std::endl;
    std::cout << table.Get(3) << std::endl;
    std::cout << table.Get(4) << std::endl;
    std::cout << table.Get(5) << std::endl;
    std::cout << table.Get(6) << std::endl;
    std::cout << table.Get(7) << std::endl;
    return 0;
}