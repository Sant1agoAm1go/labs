#include <iostream>
#include "ArraySequence.h"
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(nullptr));
    int lenght = 10;
    Sequence<int>* data = new ArraySequence<int>();
    for(int i = 0; i < lenght; i++) {
        data->Append(rand () % 100);
        std::cout << "data[" << i << "] = " << data->Get(i) << std::endl;
    }
    std::cout <<"\n";
    Sequence<int>* data2 = new ArraySequence<int>();
    for(int i = 0; i < lenght; i++) {
        data2->Append(rand () % 100);
        std::cout << "data2[" << i << "] = " << data2->Get(i) << std::endl;
    }
    std::cout <<"\n";
    Sequence<int>* result = data->Concat(data2);
    for(int i = 0; i < result->GetLength(); i++) {
        std::cout << "result[" << i << "] = " << result->Get(i) << std::endl;
    }
    delete data;
    return 0;
}