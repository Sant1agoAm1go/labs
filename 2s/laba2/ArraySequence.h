#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
template <typename T> class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* items;
public:
	ArraySequence() {
		this->items = new DynamicArray<T>();
	}

	ArraySequence(T* other, int count) { //	Копировать элементы из переданного массива
		this->items = new DynamicArray<T>(other, count);
	}

	ArraySequence(const DynamicArray<T>& other) {  //	Копирующий конструктор
		this->items = new DynamicArray<T>(other);
	}

	T GetFirst() override {
		return this->items->Get(0);
	}

	T GetLast () override {
		return this->Get(items->GetSize()-1);
	}

	T Get(int index) override {
		return this->items->Get(index);
	}

	int GetLength() override {
		return this->items->GetSize();
	}
	
	
	void Append(T item) override {
		this->items->Resize(this->items->GetSize()+1, 0);
		this->items->Set(this->items->GetSize()-1, item);
		
	}

	void Prepend(T item) override {
		this->items->Resize(this->items->GetSize()+1, 0);
		this->items->Set(0, item);
	}

	void InsertAt(T item, int index) {
		this->items->Resize(this->items->GetSize()+1, 0);
		this->items->Set(index, item);
	}

		~ArraySequence() {
		delete[] items;
	}
};
