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
	
		this->items = new T[count];
		this->items->lenght = count;
		for (int i = 0; i < items->lenght ; i++) {
			items[i] = other[i];
		}

	}

	ArraySequence(const DynamicArray<T>& dynamicArray) {  //	Копирующий конструктор
		this->items->lenght = dynamicArray.lenght;
		this->items = new T[this->items->lenght];
		for (int i = 0; i < this->items->lenght; i++)
		{
			items[i] = dynamicArray.Get(i);
		}
	}

	T GetFirst() override {
		return this->items->Get(0);
	}

	T GetLast () override {
		return this->Get(items->GetLenght()-1);
	}

	T Get(int index) override {
		return this->items->Get(index);
	}

	int GetLength() override {
		return this->items->GetLenght();
	}
	
	void Append(T item) override{
		this->items->Resize(this->items->GetSize()+1);
		this->items->Set(this->items->GetLenght()-1, item);
		
	}

	void Prepend(T item) override {
		this->items->Resize(this->items->GetSize()+1);
		this->items->Set(0, item);
	}

	void InsertAt(T item, int index) {
		this->items->Resize(this->items->GetSize()+1);
		this->items->Set(index, item);
	}

		~ArraySequence() {
		delete[] items;
	}
};
