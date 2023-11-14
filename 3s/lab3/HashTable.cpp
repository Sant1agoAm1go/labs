#include <iostream>
#include "HashTable.h"
#include "IDictionary.h"
int main() {
    HashTable<int,int> table = HashTable<int,int>(100);
    table.Add(Pair<int,int>(0,1));
    table.Add(Pair<int,int>(1,2));
    table.Add(Pair<int,int>(2,3));
    table.Add(Pair<int,int>(3,4));
    std::cout << table.Get(0) << std::endl;
    std::cout << table.Get(1) << std::endl;
    std::cout << table.Get(2) << std::endl;
    std::cout << table.Get(3) << std::endl;
    assert(table.ContainsKey(3) == true);
    assert(table.ContainsKey(4) == false);
    return 0;
}