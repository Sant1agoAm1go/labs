#include <iostream>
#include "HeapSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include <chrono>
#include <fstream>
int cmp_int(const int& a, const int& b) {
	return a - b;  	
}

int cmp_int_rev(const int& a, const int& b) {
	return (a - b)*(-1);  	
}

int cmp_double(const double& a, const double& b) {
	return (a - b >= 0) ? 1 : -1;
}

int cmp_double_rev(const double& a, const double& b) {
    return (a - b >= 0) ? -1 : 1;
}

int main() {
    srand(time(nullptr));
    int sort, len = 1000;
    double avg = 0;
    UnqPtr<ISorter<int>> sorter;
    std::cout << "Enter sort (1 - heap, 2 - shell, 3 - quick): ";
    std::cin >> sort;
    std::cout << "\n";
    switch(sort) {
        case 1:
            sorter = (new HeapSorter<int>);
            break;
        case 2:
            sorter = (new ShellSorter<int>);
            break;
        case 3:
            sorter = (new QuickSorter<int>);
            break;
    }
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 10; j++) {
            int* data2 = new int[len];
            MsPtr<int> data = MsPtr<int>(data2, len);
            for(int i = 0; i < len; i++) {
                data[i] = rand() % 100;
            }
            UnqPtr<Sequence<int>> seq = new ArraySequence<int>(*(data.Get()));
            auto start2 = std::chrono::steady_clock::now();
            UnqPtr<Sequence<int>> result = sorter->Sort(seq.Get(), cmp_int_rev);
            std::chrono::duration<double> duration = std::chrono::steady_clock::now() - start2;
            avg+= duration.count();
            delete[] data2;
        }
        avg/=10;
        std::ofstream out("time.csv", std::ios::app);
        out << avg << " " << len << "\n";
        out.close();
        len+=500;
        avg = 0;
    }
    return 0;
}
    