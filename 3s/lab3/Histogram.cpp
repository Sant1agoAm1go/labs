#include <iostream>
#include "Histogram.h"
#include "QuickSort.h"
#include "ISorter.h"
#include "PairHasher.h"
#include "Person.h"

int cmp_int(const int& a, const int& b) {
	return a - b;
}

int main() {
	srand(time(nullptr));
	int len = 10;
	Person<int> person1(10, 10, "Alexander");
	Person<int> person2(50, 50, "Boris");
	Person<int> person3(60, 60, "Dmitry");
	int data[3] = {person1.GetYear(), person2.GetYear(), person3.GetYear()};
	int data2[3] = {0 ,50, 100};
	ISorter<int>* sort = new QuickSorter<int>();
	Sequence<int>* value = new ArraySequence<int>(data, 3);
	Sequence<int>* lim = new ArraySequence<int>(data2, 3);
	SortedSequence<int>* range = new SortedSequence<int>(lim, sort, cmp_int);
	Histogram<int> histogram(value, range);
	IHasher<std::pair<int, int>>* hasher = new PairHasher<int>();
	IDictionary<std::pair<int, int>, int>* dict = histogram.BuildHistogram(hasher);
	histogram.Output(dict);
	return 0;
}