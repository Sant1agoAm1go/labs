#pragma once

#include "ArraySequence.h"
#include "IDictionary.h"
#include "ISortedSequence.h"
#include "HashTable.h"
#include "IHasher.h"
#include <utility>

template <typename Tkey> 
class Histogram {
private:
	Sequence<Tkey>* elems;
	SortedSequence<Tkey>* range;
public:
	Histogram(Sequence<Tkey>* other, SortedSequence<int>* other_range) {
		elems = other;
		range = other_range;
	}
	Histogram(Histogram<Tkey>& other) {
		elems = other.elems;
		range = other.range;
	}
	Histogram(Histogram<Tkey>&& other) {
		elems = std::move(other.elems);
		range = std::move(other.range);
	}
	~Histogram() {
		delete elems;
		delete range;
	}
	int NumberRange(std::pair<Tkey, Tkey> range) {
		int number = 0;
		for (int i = 0; i < elems->GetLength(); i++) {
			if (range.first <= elems->Get(i) && elems->Get(i) <= range.second) {
				number++;
			}
		}
		return number;
	}
	IDictionary<std::pair<Tkey, Tkey>, int>* BuildHistogram(IHasher<std::pair<Tkey, Tkey>>* hasher) {
		IDictionary<std::pair<Tkey, Tkey>, int>* hist = new HashTable<std::pair<Tkey, Tkey>, int>(hasher);
		for (int i = 0; i < range->GetLength() - 1; i++) {
			std::pair<Tkey, Tkey> span(range->Get(i), range->Get(i + 1));
			hist->Add(std::make_pair(span, NumberRange(span)));
		}
		return hist;
	}
	void OutPut(IDictionary<std::pair<Tkey, Tkey>, int>* histogram) {
		for (int i = 0; i < range->GetLength() - 1; i++) {
			std::cout << range->Get(i) << "-" << range->Get(i + 1) << ":" << histogram->Get(std::make_pair(range->Get(i), range->Get(i + 1))) << std::endl;
		}
	}
};