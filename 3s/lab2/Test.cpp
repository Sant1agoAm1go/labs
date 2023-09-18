#include <iostream>
#include "HeapSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
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
    int len, count, sort;
    double avg = 0;
    UnqPtr<ISorter<int>> sorter;
    std::cin >> len >> count >> sort;
    std::cin.clear();
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
    
    for(int j = 0; j < count; j++) {
    MsPtr<int> data = MsPtr<int>(new int[len], len);
    for(int i = 0; i < len; i++) {
        data[i] = rand() % 100;
    }
    UnqPtr<Sequence<int>> seq = new ArraySequence<int>(*(data.Get()));
    //std::cout << "Before sort: " << seq.Get() << std::endl;
    clock_t start = clock();
    UnqPtr<Sequence<int>> result = sorter->Sort(seq.Get(), cmp_int_rev);
    double time = (double) (clock() - start) / CLOCKS_PER_SEC;
    avg+=time;
    }
    avg/=count;
    std::cout << "time of sort: " << avg << std::endl;
    return 0;
}