#pragma once
#include "Sequence.h"

template <typename T> 
class ISorter {
    public:
        virtual ~ISorter() {}
        virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) = 0;
};