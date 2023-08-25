#include <iostream> 
#include "Pointers.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "Array.h"
#include <time.h>
int main() {
    srand(time(nullptr));
    int len = 1000000;
    int* data = new int[len];
    clock_t start = clock();
    for(int i = 0; i < len; i++) {
        data[i] = rand() % 100;
        UnqPtr<int>(&data[i]);
    }
    double end = (double) (clock() - start) / CLOCKS_PER_SEC;
    std::cout << end << std::endl;      
    return 0;
}