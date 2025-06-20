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
    SortSeqGen<int> generator = SortSeqGen<int>(new ShellSorter<int>());
    UnqPtr<Sequence<int>> ptr = generator.Generation(10);
    SortedSequence<int> seq = SortedSequence<int>(ptr.Get(), new ShellSorter<int>, cmp_int_rev);
    assert(seq.IsEmpty() == false);
    assert(seq.GetLength() == 10);
    std::cout << seq << "\n";
    seq.Add(364);
    seq.Add(2000);
    seq.Add(1);
    std::cout << seq.IndexOf(364) << "\n";
    std::cout << seq;
    assert(seq.GetLength() == 13);
    assert(seq.IndexOf(2000) == 0);
    assert(seq.IndexOf(1) == 12);
    assert(seq.IndexOf(0) == -1);
    return 0;
}