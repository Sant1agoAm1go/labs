#include <iostream>
#include "DynamicArray.h"
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int lenght = 10;
    DynamicArray<int>* data = new DynamicArray<int>(10,-1);
    for(int i = 0; i < lenght; i++) {
        (*data).Set(i, rand () % 100);
        std::cout << "data[" << i << "] = " << data->Get(i) << std::endl;
    }
    data->Resize(20, -1);
    for(int i = 0; i < data->GetSize(); i++)
    std::cout << "data[" << i << "] = " << data->Get(i) << std::endl;
    delete data;
    return 0;
}