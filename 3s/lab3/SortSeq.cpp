#include <iostream>
#include "SortedSequence.h"
#include "SortSeqGen.h"
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
    UnqPtr<ISorter<int>> sorter = new ShellSorter<int>;
    SortSeqGen<int> generator = SortSeqGen<int>(sorter.Get());
    SortedSequence<int> seq = SortedSequence<int>(generator.Generation(10), sorter.Get(), cmp_int_rev);
    assert(seq.IsEmpty() == false);
    assert(seq.GetLength() == 10);
    std::cout << seq << "\n";
    seq.Add(500);
    seq.Add(2000);
    seq.Add(1);
    std::cout << seq.IndexOf(500) << "\n";
    std::cout << seq;
    assert(seq.GetLength() == 13);
    return 0;
}