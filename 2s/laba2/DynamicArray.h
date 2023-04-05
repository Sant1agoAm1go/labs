#pragma once
#include <cassert>
#include <stdexcept>
#include <stdlib.h>
//TODO:Тесты на все функции
// TODO: Добавление в конец.

template <typename T> class DynamicArray 
{
private:
	T* data;
	int lenght;
	int capacity;

public:
// Конструкторы
	DynamicArray() {
		data = new T[1];
		lenght = 0;
		capacity = 0;
	}
	DynamicArray(T* items, int count) //	Копировать элементы из переданного массива
	{
		data = new T[count];
		lenght = count;
		capacity = count;
		for (int i = 0; i < lenght ; i++)
		{
			data[i] = items[i];
		}

	}
	DynamicArray(int size) //	Создать массив заданной длины
	{
		data = new T[size];
		lenght = 0;
		capacity = size;
	}
	T& operator[](const int index)
	{
		return data[index];
	}
	DynamicArray(DynamicArray<T>& dynamicArray const) //	Копирующий конструктор
	{
		lenght = dynamicArray.lenght;
		capacity = dynamicArray.capacity;
		data = new T[capacity];
		for (int i = 0; i < lenght; i++)
		{
			data[i] = dynamicArray.Get(i);
		}
	}
	
	//Деструктор
	~DynamicArray() {
		delete[] data;
	}

// Декомпозиция
	
	// Получить элемент по индексу. 
	// Может выбрасывать исключения :	− IndexOutOfRange(если индекс отрицательный, больше 
	// или равен числу элементов или указывает на не заданный элемент)
	T Get(int index)
	{
		if(index < 0 || index >= lenght ) {
			throw std::out_of_range("Out of range");
		}
		return data[index];
	}
	
	int GetSize() //	Получить размер массива
	{
		return capacity;
	}

	int GetLenght() //	Получить длину массива
	{
		return lenght;
	}
	
// Операции
	void Set(int index, T value) // Задать элемент по индексу. Может выбросить IndexOutOfRange
	{
		if(index < 0 || index >= lenght) {
			throw std::out_of_range("Out of range");
		}
		data[index] = value;
		
	}
	void Resize(int newSize)
	{
		if(newSize > 0) {
			throw std::exception("new size less than 0");
		}
		T* newData = new T[newSize];
		/*for (int i = 0; i < newSize; i++)
			newData[i] = 0;*/
		int newLenght= 0;
		newLenght = (newSize > lenght) ? lenght : newSize;
		for (int i = 0; i < newLenght; i++)
			newData[i] = data[i];
		delete[] data;
		data = newData;
		lenght = newLenght;
		capacity = newSize;
	}	
};



