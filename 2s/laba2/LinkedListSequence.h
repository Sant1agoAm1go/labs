#pragma once
#include "Sequence.h"
#include "LinkedList.h"
template <typename T> class LinkedListSequence : public Sequence<T> { 
private:
    LinkedList<T>* list;
public:
    LinkedListSequence() {
		list = new LinkedList<T>();
	}

	LinkedListSequence(T* items, int count) { //	Копировать элементы из переданного массива
        list = new LinkedList<T>(items, count);
    }

    LinkedListSequence(const LinkedList <T>& other) {  // Копирующий конструктор
        list = new LinkedList<T>(other);
    }

    LinkedListSequence(const LinkedListSequence <T>& other) {  // Копирующий конструктор
        this->list = other.list;
    }

    ~LinkedListSequence() {
        Item <T> *ptr = this->list->head, *prev;
        while (ptr != nullptr && ptr != this->list->tail->next) {
            prev = ptr;    
            ptr = ptr->next;
            delete prev;
        }
	}

	T GetFirst() override {
		//return this->list->Get(0);
        return this->list->GetFirst();
	}

	T GetLast () override {
		//return this->Get(list->GetLenght()-1);
        return this->list->GetLast();
	} 

	T Get(int index) override {
		return this->list->Get(index);
	}

	int GetLength() override {
		return this->list->GetLenght();
	}
	
	void Append(T item) override {	
        this->list->Append(item);
	}

	void Prepend(T item) override {
        this->list->Prepend(item);
	}

	void InsertAt(T item, int index) override {
        this->list->InsertAt(item, index);
	}

	Sequence <T>* Concat(Sequence <T>* other) override {
        Sequence <T>* result = new LinkedListSequence<T>();
        for (int i = 0; i < this->GetLength(); i++)
            result->Append(this->Get(i));
        for (int i = 0; i < other->GetLength(); i++)
            result->Append(other->Get(i));
        return result;
	}

	Sequence <T>* GetSubsequence(int startIndex, int endIndex, Sequence <T>* other) override {
        if(startIndex < 0 || endIndex < 0 || startIndex >= other->GetLength() || endIndex >= other->GetLength()) {
            throw std::out_of_range("Out of range");
        }
        Sequence <T>* result = new LinkedListSequence<T>();
        for (int i = startIndex; i <= endIndex; i++) {
            result->Append(other->Get(i));
        }
        return result;
    }
};