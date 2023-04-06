#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
template <class T> class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* items;
public:
	ArraySequence() {
		items = new DynamicArray<T>(0);
	}

	~ArraySequence() {
		delete items;
	}

	T GetFirst() {
		return this->Get(0);
	}

	T GetLast() {
		return this->Get(items->GetSize()-1);
	}

	T Get(int index) {
		return items->Get(index);
	}

	int GetLength() {
		return this->items->GetSize();
	}
	
	void Append(T item) {
		this->items->Resize(this->items->GetSize()+1);
		this->items->Set(this->items->GetSize()-1, item);
	}
};
