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

	ArraySequence(T* other, int count, T init) { //	Копировать элементы из переданного массива
		this->items = new DynamicArray<T>(count, init);
		/*this->items->data = new T[count];
		this->items->lenght = count;
		for (int i = 0; i < items->lenght ; i++) {
			items->data[i] = other[i];
		}*/
	}

	ArraySequence(const DynamicArray<T>& dynamicArray) {  //	Копирующий конструктор
		this->items = new DynamicArray<T>(dynamicArray);
		/*this->items->data = new T[this->items->lenght];
		this->items->lenght = dynamicArray.lenght;
		for (int i = 0; i < this->items->lenght; i++) {
			items->data[i] = dynamicArray.Get(i);
		}*/
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
