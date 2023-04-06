#pragma once
#include <iostream>
#include <cassert>
#include <stdexcept>
template <class T> class Sequence {
private:
    Item<T> *head;
    Item<T> *tail;
    int lenght;    
public:
    T GetFirst() {
        if (this->head == nullptr) {
            throw std::invalid_argument("List is empty");
        }
        return this->head->data;
    }

    T GetLast() {
        if (this->head == nullptr) {
            throw std::invalid_argument("List is empty");
        }
        return this->tail->data;
    } 

    T Get(int index) {
        if(index < 0 || index >= lenght ) {
            throw std::out_of_range("Out of range");
        }
        Item<T>* ptr = this->head; 
        for(int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->data;
    } 

    int GetLenght() {
        return this->lenght;
    }
    void Append(T item) {
        Item<T> *ptr = new Item<T>;
        if (ptr == nullptr) {
            throw std::invalid_argument("Failed to allocate memory");
        }
        ptr->data = item;
        ptr->next = nullptr;
        if (this->head == nullptr) {
            this->head = ptr;
            //this->head->prev = nullptr;
            this->tail = ptr;
        } 
        else {
            ptr->prev = this->tail;
            this->tail->next = ptr;
            this->tail = ptr;
        }
        this->lenght++;
    }

    void Prepend(T item) {
        Item<T> *ptr = new Item<T>;
        if (ptr == nullptr) {
            throw std::invalid_argument("Failed to allocate memory");
        }
        ptr->data = item;
        ptr->next = this->head;
        ptr->prev = nullptr;
        if (this->head == nullptr) {
            this->head = ptr;
            this->tail = ptr;
        }
        else {
            this->head->prev = ptr;
            this->head = ptr; 
        }
        (this->lenght)++;
    }

    void InsertAt(T item, int index) { 
        if(index < 0 || index >= lenght) {
            throw std::out_of_range("Out of range");
        }
        if(index == 0) {
            this->Prepend(item);
            return;
        }
        if (index == this->GetLenght()-1) {
            this->Append(item);
            return;
        }
        
        Item<T>* itemBefore = this->head; 
        for(int i = 0; i < index; i++) {
            itemBefore = itemBefore->next;
        }
        if (itemBefore == nullptr) {
            Append(item);
        }
        else {
            Item<T>* ptr = new Item<T>;
            ptr->data = item;
            ptr->next = itemBefore;
            ptr->prev = itemBefore->prev;
            itemBefore->prev->next = ptr;
            itemBefore->prev = ptr;
        }
        (this->lenght)++;
    }
    Sequence <T>* Concat(Sequence <T>* list) {
        for (int i = 0; i < list->lenght; i++)
            Append(list->Get(i));
        return this;
    }

    Sequence <T>* GetSubList(int startIndex, int endIndex) {
        if(startIndex < 0 || endIndex < 0 || startIndex >= lenght || endIndex >= lenght) {
            throw std::out_of_range("Out of range");
        }
        Sequence <T>* ptr = new Sequence <T>*();
        for (int i = startIndex; i <= endIndex; i++) {
            ptr->Append(Get(i));
        }
        return ptr;
    }
};

/*template <class T> class ArraySequence : public Sequence<T> {
private:
	T* data;
	int lenght;
	int capacity;
public:
// Конструкторы
	ArraySequence() {
		data = new T[1];
		lenght = 0;
		capacity = 0;
	}

	ArraySequence(T* items, int count) { //	Копировать элементы из переданного массива
	
		data = new T[count];
		lenght = count;
		capacity = count;
		for (int i = 0; i < lenght ; i++) {
			data[i] = items[i];
		}

	}

	ArraySequence(int size) { //	Создать массив заданной длины
	
		data = new T[size];
		lenght = size;
		capacity = size;
	}
	T& operator[](const int index) {
		return this->data[index];
	}

	ArraySequence(const ArraySequence<T>& ArraySequence) //	Копирующий конструктор
	{
		lenght = ArraySequence.lenght;
		capacity = ArraySequence.capacity;
		data = new T[capacity];
		for (int i = 0; i < lenght; i++)
		{
			data[i] = ArraySequence.Get(i);
		}
	}
	
	//Деструктор
	~ArraySequence() {
		delete[] data;
	}

};

template <class T> class LinkedListSequence : public Sequence<T> {
private:
    Item<T> *head;
    Item<T> *tail;
    int lenght;
public:
    LinkedListSequence() {
        head = nullptr;
        tail = nullptr;
        lenght = 0;
    }

    LinkedListSequence(T* items, int count) { //	Копировать элементы из переданного массива
        head = nullptr;
        tail = nullptr;
        for (int i = 0; i < count; i++) {
            Append(items[i]);
        }
    }

    LinkedListSequence(LinkedListSequence <T>& list) {  // Копирующий конструктор
        head = nullptr;
        tail = nullptr;
        for (int i = 0; i < list.lenght; i++) {
            Append(list.Get(i));
        }
    }

    ~LinkedListSequence() {
        delete head;
        delete tail;
    }
};*/
