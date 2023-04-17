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
    Sequence<int>* data2 = new ArraySequence<int>(*(ArraySequence<int>*)data);
    for(int i = 0; i < data->GetLength(); i++) {
        std::cout << "data2[" << i << "] = " << data2->Get(i) << std::endl;
    }
    std::cout <<"\n";
    Sequence<int>* concat = data->Concat(data2);
    for(int i = 0; i < concat->GetLength(); i++) {
        std::cout << "concat[" << i << "] = " << concat->Get(i) << std::endl;
    }

    std::cout <<"\n";
    Sequence<int>* subs = concat->GetSubsequence(5,15);
    for(int i = 0; i < subs->GetLength(); i++) {
        std::cout << "subs[" << i << "] = " << subs->Get(i) << std::endl;
    }
    delete data;
    return 0;
}