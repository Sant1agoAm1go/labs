#pragma once 
#include <stdlib.h>
#include "ArraySequence.h"
#include "Pointers.h"
#include "ISorter.h"
#include <fstream>
template <typename T> 
class GenSorter {
    private:
        UnqPtr<ISorter<T>> sorter;
        Sequence<T>* Generation(int length) {
            int* data = new int[length];
                for(int i = 0; i < length; i++) {
                 data[i] = rand() % 100;
            }
            Sequence<T>* seq = new ArraySequence<T>(data,length);
            delete[] data;
            return seq;
        }
        void WriteSeq(const char *path, Sequence<T>* seq, int length) { 
            std::ofstream out(path, std::ios::app);
            out << "{";
            for (int i = 0; i < length - 1; i++) { 
                out << (*seq)[i] << ",";
            }
            out << seq->GetLast() << "}" << std::endl;
            out.close(); 

        }
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) {
            Sequence<int>* result = (sorter.Get())->Sort(seq,cmp);
            return result;
        }
    public:
        GenSorter() {
            sorter = nullptr;
        }
        GenSorter(ISorter<T>* sort) {
            sorter = UnqPtr<ISorter<T>>(sort);
        }

        void GetSortedSequence(int length, int (*cmp)(const T&, const T&)) {
            UnqPtr<Sequence<T>> seq = Generation(length);
            UnqPtr<Sequence<T>> result = Sort(seq.Get(), cmp);
            WriteSeq("test.txt", seq.Get(), length);
            WriteSeq("test.txt", result.Get(), length);
        }

        ~GenSorter() = default;
};