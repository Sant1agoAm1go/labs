#include <iostream> 
#include "Pointers.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "Array.h"
#include <time.h>
int main() {
    srand(time(nullptr));
    int len = 100000000;
    int* data = new int[len];
    UnqPtr<int>* arr = new UnqPtr<int>[len];
    for(int i = 0; i < len; i++) {
        data[i] = rand() % 100;
    }
    clock_t start = clock();
    for(int i = 0; i < len; i++) {
        arr[i] = UnqPtr<int>(&data[i]);
    }
    double end = (double) (clock() - start) / CLOCKS_PER_SEC;
    std::cout << end << std::endl;      
    return 0;
}