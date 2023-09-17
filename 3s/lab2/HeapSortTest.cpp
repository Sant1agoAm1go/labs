#include <iostream>
#include "HeapSort.h"
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
    int data[] = {1,3,2,5,4};
    UnqPtr<ISorter<int>> sorter (new HeapSorter<int>);
    Sequence<int>* seq = new ArraySequence<int>(data, sizeof(data)/sizeof(int));
    std::cout << seq << std::endl;
    Sequence<int>* result = sorter->Sort(seq, cmp_int_rev);
    //std::cout << result << std::endl;
    return 0;
}