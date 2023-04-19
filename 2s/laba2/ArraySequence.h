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

	ArraySequence(const DynamicArray<T>& other) {  // Копирующий конструктор
    	this->items = new DynamicArray<T>(other);
    }

	ArraySequence(ArraySequence<T>& other) { //Копирующий конструктор
                this->items = new DynamicArray<T>(*other.items);
                //this->items = other.items;
		/*this->items = new DynamicArray<T>(other.GetLength(), -1);
		for(int i = 0; i < other.GetLength(); i++) {
			this->items->Set(i, other.Get(i));
		}*/
	}

	~ArraySequence() {
		delete items;
	}

	T GetFirst() const override {
		return this->items->Get(0);
	}

	T GetLast () const override{
		return this->Get(items->GetSize()-1);
	}

	T Get(int index) const override {
		return this->items->Get(index);
	}

	int GetLength() const override {
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

	void InsertAt(T item, int index) override {
		this->items->Resize(this->items->GetSize()+1, 0);
		this->items->Set(index, item);
	}

	Sequence <T>* Concat(Sequence <T>* other) override {
        Sequence <T>* result = new ArraySequence<T>();
        for (int i = 0; i < this->GetLength(); i++)
            result->Append(this->Get(i));
        for (int i = 0; i < other->GetLength(); i++)
            result->Append(other->Get(i));
        return result;
	}

	Sequence <T>* GetSubsequence(int startIndex, int endIndex) override {
        if(startIndex < 0 || endIndex < 0 || startIndex >= this->GetLength() || endIndex >= this->GetLength()) {
            throw std::out_of_range("Out of range");
        }
        Sequence <T>* result = new ArraySequence<T>();
        for (int i = startIndex; i <= endIndex; i++) {
            result->Append(this->Get(i));
        }
        return result;
    }

	Sequence <T>* Map(T (*func)(T)) {
		Sequence <T>* result = new ArraySequence<T>(); 
		for (int i = 0; i < this->GetLength(); i++) {
            result->Append(func(this->Get(i)));
        }
		return result;
	}

	Sequence <T>* Where(bool (*func)(T)) {
		Sequence <T>* result = new ArraySequence<T>();
		for (int i = 0; i < this->GetLength(); i++) {
			if(func(this->Get(i))) {
            	result->Append(this->Get(i));
			}
        }
		return result;
	}

	T Reduce(T (*func)(T,T), T start) {
		for (int i = 0; i < this->GetLength(); i++) {
			start = func(this->Get(i), start);
		}
		return start;
	}
};
