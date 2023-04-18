#pragma once
#include <cassert>
#include <stdexcept>

template <typename T> class DynamicArray {
private:
	T* data;
	int lenght;
public:
	
// Конструкторы
	DynamicArray() {
		data = new T[1];
		lenght = 0;
	}

	DynamicArray(T* other, int count) { //	Копировать элементы из переданного массива
	
		data = new T[count];
		lenght = count;
		for (int i = 0; i < lenght ; i++) {
			data[i] = other[i];
		}

	}

	DynamicArray(int size, T init) { //	Создать массив заданной длины
	
		data = new T[size];
		lenght = size;
		for(int i = 0; i < lenght; i++) {
			data[i] = init;
		}
	}

	DynamicArray(const DynamicArray<T>& other) {  //	Копирующий конструктор
		lenght = other.lenght;
		data = new T[lenght];
		for (int i = 0; i < lenght; i++) {
			this->data[i] = other.Get(i);
			//this->data[i] = other.data[i];
		}
	}
	
	~DynamicArray() {
		delete[] data;
	}

// Декомпозиция
	T Get(int index) const {
		if(index < 0 || index >= lenght ) {
			throw std::out_of_range("Out of range");
		}
		return this->data[index];
	}
	
	int GetSize() { //	Получить размер массива
	
		return this->lenght;
	}
	
// Операции
	void Set(int index, T value) { 
	
		if(index < 0 || index >= lenght) {
			throw std::out_of_range("Out of range");
		}
		this->data[index] = value;
		
	}

	void Resize(int newSize, T init) {
		if(newSize < 0) {
			throw std::invalid_argument("new size less than 0");
		}
		T* newData = new T[newSize];
		int tempLenght =(newSize > lenght) ? lenght : newSize;
		for (int i = 0; i < tempLenght; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		if(tempLenght < newSize) { 
			for(int i = tempLenght; i < newSize; i++) {
				newData[i] = init;
			}
		}
		this->data = newData;
		this->lenght = newSize;
	}
	T& operator[](int index) {
		return this->data[index];
	}
}; 

/*
template <typename T, typename... Args> 
Sequence<T>* Sequence<T>::Append(Args... args) 
{
((this->Append(args)),...) ;

return this;*/
 


