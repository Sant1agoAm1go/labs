#pragma once
#include <stdexcept>
template <typename T> class DynamicArray {
private:
	T* data;
	int length;
public:
	
	DynamicArray() {
		data = new T[1];
		data[0] = T();
		length = 0;
	}

	DynamicArray(T* other, int count) { // Копировать элементы из переданного массива
	
		data = new T[count];
		length = count;
		for (int i = 0; i < length ; i++) {
			data[i] = other[i];
		}

	}

	DynamicArray(int size) { //	Создать массив заданной длины
	
		data = new T[size];
		length = size;
		for(int i = 0; i < length; i++) {
			data[i] = T();
		}
	}

	DynamicArray(const DynamicArray<T>& other) {  // Копирующий конструктор
		length = other.length;
		data = new T[length];
		for (int i = 0; i < length; i++) {
			this->data[i] = other.Get(i);
			//this->data[i] = other.data[i];
		}
	}
	
	~DynamicArray() {
		delete[] data;
	}

	T& Get(int index) const {
		if(index < 0 || index >= length ) {
			throw std::out_of_range("Out of range");
		}
		return this->data[index];
	}
	
	int GetSize() const { 
	
		return this->length;
	}
	
	void Set(int index, T value) { 
	
		if(index < 0 || index >= length) {
			throw std::out_of_range("Out of range");
		}
		this->data[index] = value;
		
	}

	void Resize(int newSize) {
		if(newSize < 0) {
			throw std::invalid_argument("new size less than 0");
		}
		T* newData = new T[newSize];
		int tempLength =(newSize > length) ? length : newSize;
		for (int i = 0; i < tempLength; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		if(tempLength < newSize) { 
			for(int i = tempLength; i < newSize; i++) {
				newData[i] = T();
			}
		}
		this->data = newData;
		this->length = newSize;
	}

	T& operator[](int index) {
		if(index < 0 || index >= length ) {
			throw std::out_of_range("Out of range");
		}
		return this->data[index];
	}

	DynamicArray<T>* operator+(const DynamicArray<T>* other) {
		DynamicArray<T>* result = new DynamicArray<T>(this->GetSize()+other->GetSize());
		for(int i = 0 ; i < this->GetSize(); i++) {
			this->Set(i, this->Get(i));
		}
		for(int i = this->GetSize() ; i < result->GetSize() ; i++) {
			this->Set(i, this->Get(i));
		}
		return result;
	}

	DynamicArray<T>& operator+(const DynamicArray<T>& other) {
		int oldSize = this->GetSize();
		this->Resize(oldSize+other.GetSize());
		for(int i = oldSize ; i < this->GetSize(); i++) {
			this->Set(i, other.Get(i));
		}
		return *this;
	}
}; 

/*
template <typename T, typename... Args> 
Sequence<T>* Sequence<T>::Append(Args... args) 
{
((this->Append(args)),...) ;

return this;
}*/


