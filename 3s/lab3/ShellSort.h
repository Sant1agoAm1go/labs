#pragma once
#include "ISorter.h"
#include "ArraySequence.h"
#include "Pointers.h"
template <typename T> 
class ShellSorter : public ISorter <T> {
    private:
        void ShellSort(Sequence<T>* seq, int (*cmp)(const T&, const T&), int len) {
            for (int s = len / 2; s > 0; s /= 2) {
                for (int i = s; i < len; i++) {
                    for (int j = i - s; j >= 0 && cmp((*seq)[j], (*seq)[j + s]) > 0; j -= s) {
                        Swap((*seq)[j], (*seq)[j+s]);
                    }
                }
            }
        }
    public:
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) {
            Sequence<T>* result = seq->GetSubsequence(0, seq->GetLength() - 1);
            ShellSort(result, cmp, result->GetLength());
            return result;
        }   
};