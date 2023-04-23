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
    Sequence<int>* arr = new LinkedListSequence<int>();
    for(int i = 0; i < lenght; i++) {
        arr->Append(rand () % 100);
    }
    assert(arr->GetLength() == 10);

    Sequence<int>* arr2 = new LinkedListSequence<int>(*(LinkedListSequence<int>*) arr);
    for(int i = 0; i < arr2->GetLength(); i++) {
        assert(arr2->Get(i) == arr->Get(i));
    }

    assert(arr2->GetLength() == 10);
    //std::cout << "LOH" << std::endl;
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

    std::cout << wheres->Reduce(reducer, 0) << std::endl;
    delete arr;
    delete arr2; 
    delete concat;
    delete subs;
    delete wheres;
    return 0;
}