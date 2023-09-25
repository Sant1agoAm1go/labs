#pragma once 
#include <stdlib.h>
#include "ArraySequence.h"
#include "Pointers.h"
template <typename T> 
class Generator {
    public:
    Sequence<T>* Generation(int length, T* data, T (*func)(T)) {
        UnqPtr<Sequence<T>> result = new ArraySequence<T>(data,length);
        return result->Map(func);
    }

};