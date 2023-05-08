#include <iostream>
#include <cassert>
#include <time.h>
#include "Array.h"
#include "Allocator.h"
int main() {
    srand(time(nullptr));

        DynamicArray<int>* arr =  Allocator<int>::AllocateArray(10);
    for(int i = 0; i < arr->GetSize(); i++) {
        arr->Set(i, rand () % 100);
        assert((*arr)[i] == arr->Get(i));
    }

    arr->Resize(20);
    assert(arr->GetSize() == 20); 

    DynamicArray<int>* arr2 = new DynamicArray<int>(*arr);
    for(int i = 0; i < arr->GetSize(); i++) {
        assert(arr2->Get(i) == arr->Get(i)); 
    }
    
    delete arr;
    delete arr2;
    return 0;
}