#pragma once
#include "ISorter.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Pointers.h"
template <typename T> 
class QuickSorter : public ISorter <T> {
    private:
        int Partition(Sequence<T>* seq, int (*cmp)(const T&, const T&), int start, int end) {
            int pivot = (*seq)[end];
            int pIndex = start;
            for (int i = start; i < end; i++) {
                if (cmp((*seq)[i], pivot) <= 0) {
                    Swap((*seq)[i], (*seq)[pIndex]);
                    pIndex++;
                }
            }
            Swap((*seq)[pIndex], (*seq)[end]);
            return pIndex;
        }
        void QuickSort(Sequence<T>* seq, int (*cmp)(const T&, const T&), int start, int end) {
            if (start >= end) {
                return;
            }
            int pivot = Partition(seq, cmp, start, end);
            QuickSort(seq, cmp, start, pivot - 1);
            QuickSort(seq, cmp, pivot + 1, end);
        }
    public:
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) {
            Sequence<T>* result = seq->GetSubsequence(0, seq->GetLength() - 1);
            QuickSort(result, cmp, 0, result->GetLength() - 1);
            return result;
        }  
};