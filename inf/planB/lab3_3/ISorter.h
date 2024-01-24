#pragma once
#include "Sequence.h"
template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
template <typename T> 
class ISorter {
    public:
        virtual ~ISorter() {}
        virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) = 0;
};