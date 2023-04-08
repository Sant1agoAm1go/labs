#include <iostream>
#include "LinkedListSequence.h"
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(nullptr));
    int lenght = 10;
    Sequence<int>* data = new LinkedListSequence<int>();
    for(int i = 0; i < lenght; i++) {
        data->Append(rand () % 100);
        std::cout << "data[" << i << "] = " << data->Get(i) << std::endl;
    }
    
    delete data;
    return 0;
}