#pragma once
#include "Sequence.h"
template <typename T> class Vector : public Sequence<T> {
private:
        T* data;
        int lenght;
public:
    Vector() {
        data = new T[1];
        lenght = 0;
    }

    Vector(T* other, int count) { // Копировать элементы из переданного массива
	
		data = new T[count];
		lenght = count;
		for (int i = 0; i < lenght ; i++) {
			data[i] = other[i];
		}

	}

	Vector(int size, T init) { //	Создать вектор заданной длины
	
		data = new T[size];
		lenght = size;
		for(int i = 0; i < lenght; i++) {
			data[i] = init;
		}
	}

	Vector(const DynamicArray<T>& other) {  // Копирующий конструктор
		lenght = other.lenght;
		data = new T[lenght];
		for (int i = 0; i < lenght; i++) {
			this->data[i] = other.Get(i);
		}
	}

    ~Vector() {
        delete[] data;
    }

    T Get(int index) const override {
        if(index < 0 || index >= lenght ) {
            throw std::out_of_range("Out of range");
        }
        return this->data[index];
	}

    void Set(int index, T value) { 
	
		if(index < 0 || index >= lenght) {
			throw std::out_of_range("Out of range");
		}
		this->data[index] = value;
		
	}

    T GetFirst() const override {
        return this->Get(0);
    }

    T GetLast() const override {
        return this->Get(this->GetLenght()-1);
    }

    int GetLenght() const override { //	Получить размер массива
	    return this->lenght;
	}

    void Append(T item) override {
	    this->Set(this->GetLenght()-1, item);
		
	}

	void Prepend(T item) override {
		this->Set(0, item);
	}

	void InsertAt(T item, int index) override {
		this->Set(index, item);
	}

    Sequence <T>* Concat(Sequence <T>* other) override {
        Sequence <T>* result = new Vector<T>();
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
        Sequence <T>* result = new Vector<T>();
        for (int i = startIndex; i <= endIndex; i++) {
            result->Append(this->Get(i));
        }
        return result;
    }

	Sequence <T>* Map(T (*func)(T)) override {
		Sequence <T>* result = new Vector<T>(); 
		for (int i = 0; i < this->GetLength(); i++) {
            result->Append(func(this->Get(i)));
        }
		return result;
	}

	Sequence <T>* Where(bool (*func)(T)) override {
		Sequence <T>* result = new Vector<T>();
		for (int i = 0; i < this->GetLength(); i++) {
			if(func(this->Get(i))) {
            	result->Append(this->Get(i));
			}
        }
		return result;
	}

	T Reduce(T (*func)(T,T), T start) override {
		for (int i = 0; i < this->GetLength(); i++) {
			start = func(this->Get(i), start);
		}
		return start;
	}

	Sequence <T>* Slice(int index, int number, Sequence<T>* seq) {
		if(std::abs(index) > this->GetLength() || index+number > this->GetLength()) {
			throw std::out_of_range("Out of range");
		}
		Sequence <T>* result = new Vector<T>();
		int resInd = 0;
		if(index >= 0) {
			for(int i = 0; i < index; i++) {
					result->InsertAt(this->Get(i), resInd);
					resInd++;
			}
			for(int i = index+number; i < this->GetLength(); i++) {
					result->InsertAt(this->Get(i), resInd);
					resInd++;
			}
			if(seq->GetLength() != 0) {
				int seqInd = 0;
				for(int i = index; i <= index+seq->GetLength()-1; i++) {
					result->InsertAt(seq->Get(seqInd), i);
					seqInd++;
				}
			} 
		}
		return result;
	}
};