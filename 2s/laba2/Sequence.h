#pragma once
#include <iostream>
#include <cassert>
#include <stdexcept>
/*template <typename T> struct Item {
public:
    T data;
    struct Item *next;
    struct Item *prev;

};*/
template <typename T> class Sequence {
/*private:
    Item<T> *head;
    Item<T> *tail;
    int lenght;*/    
public:
    virtual T GetFirst() = 0; 

    virtual T GetLast() = 0;

    virtual T Get(int index) = 0;

    virtual int GetLength() = 0;

    virtual void Append(T item) = 0;

    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, int index) = 0;

    Sequence <T>* Concat(Sequence <T>* other) {
        Sequence <T>* result = new Sequence <T>*();
        for (int i = 0; i < this->GetLenght(); i++)
            result->Append(this->Get(i));
        for (int i = 0; i < other->GetLenght(); i++)
            result->Append(other->Get(i));
        return result;
    }

    Sequence <T>* GetSubList(int startIndex, int endIndex) {
        if(startIndex < 0 || endIndex < 0 || startIndex >= this->GetLength() || endIndex >= this->GetLength()) {
            throw std::out_of_range("Out of range");
        }
        Sequence <T>* result = new Sequence <T>*();
        for (int i = startIndex; i <= endIndex; i++) {
            result->Append(Get(i));
        }
        return result;
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
