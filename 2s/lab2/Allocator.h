#pragma once 
#include "Array.h"
#include "List.h"
#include "ArraySequence.h"
#include "ListSequence.h"
template <typename T> class Allocator {
public:
    template<typename... Args> 
    static DynamicArray<T>* AllocateArray(Args... args) {
        return new DynamicArray<T>(args...);
    }

    template <typename... Args>
    static LinkedList<T>* AllocateList(Args... args) {
        return new LinkedList<T>(args...);
    }

    template <typename... Args>
    static Sequence<T>* AllocateArraySequence(Args... args) {
        return (Sequence<T>*) new ArraySequence<T>(args...);
    }

    template <typename... Args>
    static Sequence<T>* AllocateListSequence(Args... args) {
        return (Sequence<T>*) new LinkedListSequence<T>(args...);
    }
};