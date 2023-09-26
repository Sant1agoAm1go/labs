#pragma once 
#include <stdlib.h>
#include "ArraySequence.h"
#include "Pointers.h"
#include <fstream>
template <typename T> 
class Generator {
    public:
    Sequence<T>* Generation(int length, T* data, T (*func)(T)) {
        UnqPtr<Sequence<T>> result = new ArraySequence<T>(data,length);
        return result->Map(func);
    }

    void write_point(const char *path, Sequence<T>* seq, int length) { 
        std::ofstream out(path, std::ios::app);
        out << "{";
	for (int i = 0; i < length - 1; i++) { 
		out << seq[i] << ",";
	}
    out << seq->GetLast() << "}" << std::endl;
	out.close(); 
}
};