#include <iostream>
#include "QuickSort.h"
int cmp_int(const int& p1, const int& p2) {
	return p1 - p2;  	
}

int cmp_int_rev(const int& p1, const int& p2) {
	return (p1 - p2)*(-1);  	
}

int cmp_double(const double& p1, const double& p2) {
	return (p1 - p2 >= 0) ? 1 : -1;
}

int cmp_double_rev(const double& p1, const double& p2) {
    return (p1 - p2 >= 0) ? -1 : 1;
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
    std::cout << "Before sort: " << seq.Get() << std::endl;
    Sequence<int>* result = sorter->Sort(seq.Get(), cmp_int_rev);
    std::cout << "After sort: " << result << std::endl;
    std::cout << "Everything is fine" << std::endl;
    return 0;
}