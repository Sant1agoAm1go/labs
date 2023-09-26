#include <iostream>
#include <stdlib.h>
#include "ArraySequence.h"
#include "Pointers.h"
#include <fstream>
//#include "Generator.h"
    int map(int a) {
        a = a*3;
        return a;
    }
    Sequence<int>* Generation(int length, int* data, int (*func)(int)) {
        UnqPtr<Sequence<int>> result = new ArraySequence<int>(data,length);
        return result->Map(func);
    }
    
    void write_point(const char *path, Sequence<int>* seq, int length) { 
        std::ofstream out(path, std::ios::app);
        out << "{";
        for (int i = 0; i < length - 1; i++) { 
            out << seq->Get(i) << ",";
        }
        out << seq->GetLast() << "}" << std::endl;
        out.close(); 
    }
int main() {
    srand(time(nullptr));
    int len;
    std::cin >> len;
    int* data = new int[len];
    for(int i = 0; i < len; i++) {
        data[i] = rand() % 100;
    }
    UnqPtr<Sequence<int>> seq = Generation(len, data, map);
    write_point("test.txt",seq.Get(), len);
    delete[] data;
    return 0;
}