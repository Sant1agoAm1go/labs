#include <iostream>
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
    int len;
    std::cin >> len;
    std::cin.clear();
    UnqPtr<int> data = new int[len];
    for(int i = 0; i < len; i++) {
        data[i] = rand() % 100;
    }
    UnqPtr<ISorter<int>> sorter (new QuickSorter<int>);
    UnqPtr<Sequence<int>> seq = new ArraySequence<int>(data.Get(), len);
    //std::cout << "Before sort: " << seq.Get() << std::endl;
    clock_t start = clock();
    Sequence<int>* result = sorter->Sort(seq.Get(), cmp_int_rev);
    double time = (double) (clock() - start) / CLOCKS_PER_SEC;
    std::cout << "time of sort: " << time << std::endl;
    std::cout << "After sort: " << result << std::endl;
    std::cout << "Everything is fine" << std::endl;
    return 0;
}