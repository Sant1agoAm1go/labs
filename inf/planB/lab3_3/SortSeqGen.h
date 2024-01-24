#pragma once 
#include <stdlib.h>
#include "ArraySequence.h"
#include "Pointers.h"
#include "ISorter.h"
#include <math.h>
#include <fstream>
#include <utility>
template <typename T> 
class SortSeqGen {
    private:
        UnqPtr<ISorter<T>> sorter;
    public:
        Sequence<T>* Generation(int length) {
            int* data = new int[length];
                for(int i = 0; i < length; i++) {
                 data[i] = rand() % ((int)(std::pow(2,length)));
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
        
        SortSeqGen() {
            sorter = nullptr;
        }
        SortSeqGen(ISorter<T>* sort) {
            sorter = UnqPtr<ISorter<T>>(sort);
        }

        SortSeqGen(const SortSeqGen<T>& generator) {
            sorter = generator.sorter;
        }

        SortSeqGen(SortSeqGen<T>&& generator) {
            sorter = std::move(generator.sorter);
            generator.sorter = nullptr;
        }


        void GetSortedSequence(int length, int (*cmp)(const T&, const T&)) {
            UnqPtr<Sequence<T>> seq = Generation(length);
            UnqPtr<Sequence<T>> result = Sort(seq.Get(), cmp);
            WriteSeq("test.csv", seq.Get(), length);
            WriteSeq("test.csv", result.Get(), length);
        }

        
        SortSeqGen<T>& operator=(const SortSeqGen<T>& generator) {
            sorter = generator.sorter;
        }

        SortSeqGen<T>& operator=(SortSeqGen<T>&& generator) {
            sorter = std::exchange(generator.sorter, nullptr);
            //generator.sorter = nullptr;
        }
        
        ~SortSeqGen() = default;
};