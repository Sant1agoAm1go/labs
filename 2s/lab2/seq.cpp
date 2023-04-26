#include <iostream>
#include "ArraySequence.h"
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int lenght = 5;
    ArraySequence<int>* data = new ArraySequence<int>();
    for (int i = 0; i < lenght; i++) {
        data->Append(rand() % 100);   
    }
    lenght = data->GetLenght();
    for (int i = 0; i < lenght; i++) {
       std::cout << "data[" << i << "] = " << data->Get(i) << std::endl;
    }

    /*for (int i = 0; i <lenght; i++) {
        data->Prepend(rand() % 100);   
    }
    std::cout << "\n";
    lenght = data->GetLenght();
    for (int i = 0; i < lenght; i++) {
       std::cout << "data[" << i << "] = " << data->Get(i) << std::endl;
    }
    data->InsertAt(10,7);
    lenght = data->GetLenght();
    std::cout << "\n";
    for (int i = 0; i < lenght; i++) {
        std::cout << "data[" << i << "] = " << data->Get(i) << std::endl;
    }*/
    delete data;
    return 0;
}