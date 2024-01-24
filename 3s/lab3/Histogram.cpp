#include <iostream>
#include "Histogram.h"
#include "QuickSort.h"
#include "ISorter.h"
#include "PairHasher.h"

int cmp_int(const int& a, const int& b) {
	return a - b;
}

int main() {
	srand(time(nullptr));
	int len = 10;
	int* data = new int[len];
	for(int i = 0; i < len; i++) {
		data[i] = rand() % 100;
		std::cout << data[i] << std::endl;
	}
	int data2[3] = {0 ,50, 100};
	ISorter<int>* sort = new QuickSorter<int>();
	Sequence<int>* value = new ArraySequence<int>(data, 20);
	Sequence<int>* lim = new ArraySequence<int>(data2, 3);
	SortedSequence<int>* range = new SortedSequence<int>(lim, sort, cmp_int);
	Histogram<int> hist1(value, range);
	IHasher<std::pair<int, int>>* hasher = new PairHasher<int>();
	IDictionary<std::pair<int, int>, int>* dict = hist1.BuildHistogram(hasher);
	hist1.OutPut(dict);
	return 0;
}