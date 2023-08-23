#include <iostream> 
#include "Pointers.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "Array.h"
int main() {
    int data[] = {1,2,3,4,5};
    Sequence<int>* seq = new ArraySequence<int>(data, sizeof(data)/sizeof(int));
    UnqPtr<int> ptr = nullptr;
    std::cout << ptr << std::endl;
    UnqPtr<int> ptr2 = UnqPtr<int>(data);
    UnqPtr<Sequence<int>> ptr3 = UnqPtr<Sequence<int>>(seq);
    std::cout << ptr3->Get(2) << std::endl;
    return 0;
}