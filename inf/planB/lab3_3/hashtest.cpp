#include <iostream>
#include "STLHasher.h"
int main () {
    IHasher<int>* hasher = new STLHasher<int>();
    std::cout << hasher->Hash(100) << std::endl;
    return 0;
}