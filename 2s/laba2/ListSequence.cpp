#include <iostream>
#include "ListSequence.h"
#include <time.h>
bool func(int value) {
    return value % 2 == 0;
}

int reducer(int a, int b) {
    return 2*a + 3*b;
}
int main() {
    srand(time(nullptr));
    int lenght = 10;
    Sequence<int>* data = new LinkedListSequence<int>();
    for(int i = 0; i < lenght; i++) {
        data->Append(rand () % 100);
        std::cout << "data[" << i << "] = " << data->Get(i) << std::endl;
    }
    std::cout <<"\n";
    Sequence<int>* data2 = new LinkedListSequence<int>(*(LinkedListSequence<int>*)data);
    for(int i = 0; i < data2->GetLength(); i++) {
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

    std::cout <<"\n";
    Sequence<int>* wheres = subs->Where(func);
    for(int i = 0; i < wheres->GetLength(); i++) {
        std::cout << "wheres[" << i << "] = " << wheres->Get(i) << std::endl;
    }

    std::cout <<"\n";
    std::cout << wheres->Reduce(reducer, 0) << std::endl;
    delete data;
    return 0;
}