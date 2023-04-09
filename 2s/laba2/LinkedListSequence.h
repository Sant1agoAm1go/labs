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
        this->list->head = nullptr;
        this->list->tail = nullptr;
        for (int i = 0; i < count; i++) {
            this->list->Append(items[i]);
        }
    }

    LinkedListSequence(const LinkedList <T>& other) {  // Копирующий конструктор
        this->list->head = nullptr;
        this->list->tail = nullptr;
        for (int i = 0; i < other.lenght; i++) {
            this->list->Append(other.Get(i));
        }
    }

	T GetFirst() override {
		return this->list->Get(0);
	}

	T GetLast () override {
		return this->Get(list->GetLenght()-1);
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

	void InsertAt(T item, int index) {
        this->list->InsertAt(item, index);
	}

	~LinkedListSequence() {
        Item <T> *ptr = this->list->head, *prev;
        while (ptr != nullptr && ptr != this->list->tail->next) {
            prev = ptr;    
            ptr = ptr->next;
            delete prev;
        }
	}
};