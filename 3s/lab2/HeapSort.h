#pragma once
#include "ISorter.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Pointers.h"
template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T> 
class HeapSorter : public ISorter <T> {
    private:
        void Heapify(Sequence<T>* seq, int (*cmp)(const T&, const T&), int n, int i) {
            int largest = i;   
            int l = 2*i + 1; 
            int r = 2*i + 2; 

            if (l < n && cmp(seq->Get(l),seq->Get(largest)) > 0)
                largest = l;
            if (r < n && cmp(seq->Get(r),seq->Get(largest)) > 0)
                largest = r;

            if (largest != i) {
                Swap(seq->Get(i), seq->Get(largest));
                Heapify(seq, cmp, n, largest);
            }
        }
        void HeapSort(Sequence<T>* seq, int (*cmp)(const T&, const T&), int n) {
            for (int i = n / 2 - 1; i >= 0; i--)
                Heapify(seq, cmp, n, i);
            for (int i=n-1; i>=0; i--) {
                Swap(seq->Get(0), seq->Get(i));
                Heapify(seq, cmp, i, 0);
            }
        }
    public:
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) {
            Sequence<T>* result = seq->GetSubsequence(0, seq->GetLength());
            HeapSort(result, cmp, result->GetLength());
            return result;
        }   

};