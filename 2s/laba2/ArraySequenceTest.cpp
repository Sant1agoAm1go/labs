#include <iostream>
#include "ArraySequence.h"
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
    Sequence<int>* arr = new ArraySequence<int>();
    for(int i = 0; i < lenght; i++) {
        arr->Append(rand () % 100);
    }

    Sequence<int>* arr2 = new ArraySequence<int>(*(ArraySequence<int>*)arr);
    for(int i = 0; i < arr2->GetLength(); i++) {
        assert(arr2->Get(i) == arr->Get(i));
    }

    Sequence<int>* concat = arr->Concat(arr2);
    for(int i = 0; i < arr->GetLength(); i++) {
        assert(concat->Get(i) == arr->Get(i));
    }

    int index = 0;
    for(int i = arr->GetLength(); i < arr2->GetLength(); i++) {
        assert(concat->Get(i) == arr2->Get(index));
        index++;
    }

    Sequence<int>* subs = concat->GetSubsequence(5,15);
    for(int i = 0; i < subs->GetLength(); i++) {
        assert(subs->Get(i) == concat->Get(i+5));
    }

    Sequence<int>* wheres = subs->Where(func);

    for(int i = 0; i < wheres->GetLength(); i++) {
        assert(func(wheres->Get(i)) == true);
    }
    
    int* data = new int[3];
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    Sequence<int>* reduce_check = new ArraySequence<int>(data,3);

    assert(reduce_check->Reduce(reducer, 4) == 144);
    std::cout << reduce_check->Reduce(reducer, 4) << std::endl;
    delete arr;
    delete arr2; 
    delete concat;
    delete subs;
    delete wheres;
    return 0;
}