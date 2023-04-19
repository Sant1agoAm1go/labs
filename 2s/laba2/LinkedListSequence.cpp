#include <iostream>
#include "LinkedListSequence.h"
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(nullptr));
    int lenght = 10;
    Sequence<char>* data = new LinkedListSequence<char>();
    for(int i = 0; i < lenght; i++) {
        data->Append('A');
        std::cout << "data[" << i << "] = " << data->Get(i) << std::endl;
    }
    
    delete data;
    return 0;
}