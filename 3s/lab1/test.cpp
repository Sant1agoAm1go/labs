#include <iostream> 
#include "Pointers.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "Array.h"
int main() {
    srand(time(nullptr));
    int* data = new int[5];
    for(int i = 0; i < 5; i++) {
        data[i] = rand() % 100;
    }
    int a = 5;
    Sequence<int>* seq = new ArraySequence<int>(data, 5);
    UnqPtr<int> ptr = UnqPtr<int>(&a);
    std::cout << ptr << std::endl;
    UnqPtr<int> ptr2 = UnqPtr<int>(std::move(ptr));
    UnqPtr<Sequence<int>> ptr3 = UnqPtr<Sequence<int>>(seq);
    //std::cout << ptr3->Get(2) << std::endl;
    *ptr2 = 7;
    std::cout << *ptr2 << std::endl;
    return 0;
}