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
    UnqPtr<int> ptr2 (new int(a));
    UnqPtr<Sequence<int>> ptr3 = UnqPtr<Sequence<int>>(seq);
    std::cout << ptr3->Get(2) << std::endl;
    *ptr2 = 7;
    std::cout << *ptr2 << std::endl;

    int* data2 = new int[5];
    for(int i = 0; i < 5; i++) {
        data2[i] = rand() % 100;
    }
    MemorySpan<int> span = MemorySpan<int>(data2, 5);
    std::cout << span.Get(3) << std::endl;
    return 0;
}