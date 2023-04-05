#pragma once
#include <iostream>
#include <cassert>
#include <stdexcept>
#include "DynamicArray.h"
#include "LinkedList.h"
template <class T> class Sequence {
    T GetFirst();
    T GetLast();
    T Get(int index);
    Sequence<T>* GetSubsequence(int startIndex, int endIndex);
    int GetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    Sequence <T>* Concat(Sequence <T> *list);
};
template <class T> class ArraySequence : Sequence<T> {
    public:
    ArraySequence ();
    ArraySequence (LinkedList <T> & list const);
};
template <class T> class LinkedListSequence : Sequence<T> {
    public:
    LinkedListSequence ();
    LinkedListSequence (LinkedList <T> & list const);
};
