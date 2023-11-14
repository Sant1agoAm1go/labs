#include <iostream>
#include "Pair.h"
int main() {
    Pair<int,int> pair = Pair<int,int>(20,30);
    std::cout << pair.Get1() << std::endl;
    std::cout << pair.Get2() << std::endl;
    return 0;
}