#pragma once
#include <cassert>
#include <stdexcept>

template <typename T> class DynamicArray {
private:
	T* data;
	int capacity;
	int lenght;
public:
	
// Конструкторы
	DynamicArray() {
		data = new T[1];
		lenght = 0;
		capacity = 1;
	}

	DynamicArray(T* items, int count) { //	Копировать элементы из переданного массива
	
		data = new T[count];
		lenght = count;
		capacity = count;
		for (int i = 0; i < lenght ; i++) {
			data[i] = items[i];
		}

	}

	DynamicArray(int size) { //	Создать массив заданной длины
	
		data = new T[size];
		lenght = size;
		capacity = size;
	}
	T& operator[](const int index) {
		return this->data[index];
	}

	DynamicArray(const DynamicArray<T>& dynamicArray)  //	Копирующий конструктор
	{
		lenght = dynamicArray.lenght;
		capacity = dynamicArray.capacity;
		data = new T[capacity];
		for (int i = 0; i < lenght; i++)
		{
			data[i] = dynamicArray.Get(i);
		}
	}
	
	~DynamicArray() {
		delete[] data;
	}

// Декомпозиция
	T Get(int index) {
		if(index < 0 || index >= lenght ) {
			throw std::out_of_range("Out of range");
		}
		return this->data[index];
	}
	
	int GetSize() { //	Получить размер массива
	
		return this->capacity;
	}

	int GetLenght() { //	Получить длину массива
		return this->lenght;
	}
	
// Операции
	void Set(int index, T value) { 
	
		if(index < 0 || index >= lenght) {
			throw std::out_of_range("Out of range");
		}
		this->data[index] = value;
		
	}

	void Resize(int newSize) {
		if(newSize < 0) {
			throw std::invalid_argument("new size less than 0");
		}
		T* newData = new T[newSize];
		int newLenght =(newSize > lenght) ? lenght : newSize;
		for (int i = 0; i < newLenght; i++)
			newData[i] = data[i];
		delete[] data;
		this->data = newData;
		this->lenght = newLenght;
		this->capacity = newSize;
	}

	void SetLenght(int newLenght) {
		this->lenght = newLenght;
	}	
};



