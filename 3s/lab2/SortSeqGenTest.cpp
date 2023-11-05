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
    int length, sort;
    UnqPtr<ISorter<int>> sorter;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "\n";
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
    SortSeqGen<int> generator = SortSeqGen<int>(sorter.Get());
    while(length > 0) {
        generator.GetSortedSequence(length,cmp_int_rev);
        length--;
    }
    return 0;
}