#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
template <typename T> class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* items;
public:
	ArraySequence() {
		items = new DynamicArray<T>();
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
		this->items->SetLenght(this->items->GetLenght()+1);
		this->items->Set(this->items->GetLenght()-1, item);
		
	}

	void Prepend(T item) override {
		this->items->Resize(this->items->GetSize()+1);
		this->items->Set(0, item);
		this->items->SetLenght(this->items->GetLenght()+1);
	}

	void InsertAt(T item, int index) {
		this->items->Resize(this->items->GetSize()+1);
		this->items->Set(index, item);
		this->items->SetLenght(this->items->GetLenght()+1);
	}

		~ArraySequence() {
		delete[] items;
	}
};
