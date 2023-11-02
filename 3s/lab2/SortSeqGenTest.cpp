#include <iostream>
#include <stdlib.h>
#include "ArraySequence.h"
#include "Pointers.h"
#include <fstream>
#include "SortSeqGen.h"
#include "HeapSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include <chrono>
int cmp_int_rev(const int& a, const int& b) {
	return (a - b)*(-1);  	
}
int main() {
    srand(time(nullptr));
    int length;
    std::cin >> length;
    SortSeqGen<int> generator = SortSeqGen<int>(new QuickSorter<int>);
    while(length > 0) {
        generator.GetSortedSequence(length,cmp_int_rev);
        length--;
    }
    return 0;
}