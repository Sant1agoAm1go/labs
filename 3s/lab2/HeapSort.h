#pragma once
#include "ISorter.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Pointers.h"
template <typename T> 
class HeapSorter : public ISorter <T> {
    private:
        void Heapify(Sequence<T>* seq, int (*cmp)(const T&, const T&), int len, int i) {
            int largest = i;   
            int l = 2*i + 1; 
            int r = 2*i + 2; 

            if (l < len && cmp((*seq)[l],(*seq)[largest]) > 0)
                largest = l;
            if (r < len && cmp((*seq)[r],(*seq)[largest]) > 0)
                largest = r;

            if (largest != i) {
                Swap((*seq)[i], (*seq)[largest]);
                Heapify(seq, cmp, len, largest);
            }
        }
        void HeapSort(Sequence<T>* seq, int (*cmp)(const T&, const T&), int len) {
            for (int i = len / 2 - 1; i >= 0; i--)
                Heapify(seq, cmp, len, i);
            for (int i=len-1; i>=0; i--) {
                Swap((*seq)[0], (*seq)[i]);
                Heapify(seq, cmp, i, 0);
            }
        }
    public:
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) {
            Sequence<T>* result = seq->GetSubsequence(0, seq->GetLength() - 1);
            HeapSort(result, cmp, result->GetLength());
            return result;
        }   

};