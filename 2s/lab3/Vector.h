#pragma once
#include <ArraySequence.h>
#include <math.h>
template <typename T> class Vector {
private:
    T* data;
    int length;
public:
    Vector() {
        data = new T[1];
		data[0] = T();
        length = 0;
    }

    Vector(T* other, int count) { // Копировать координаты из переданного вектора
	
		data = new T[count];
		length = count;
		for (int i = 0; i < length ; i++) {
			data[i] = other[i];
		}

	}

	Vector(int size) { //	Создать вектор заданной длины
	
		data = new T[size];
		length = size;
		for(int i = 0; i < length; i++) {
			data[i] = T();
		}
	}

	Vector(const Vector<T>& other) {  // Копирующий конструктор
		length = other.length;
		data = new T[length];
		for (int i = 0; i < length; i++) {
			this->data[i] = other.Get(i);
		}
	}

    ~Vector() {
        delete[] data;
    }

    T Get(int index) const override {
        if(index < 0 || index >= length ) {
            throw std::out_of_range("Out of range");
        }
        return this->data[index];
	}

    void Set(int index, T value) { 
	
		if(index < 0 || index >= length) {
			throw std::out_of_range("Out of range");
		}
		this->data[index] = value;
		
	}

    T GetFirst() const {
        return this->Get(0);
    }

    T GetLast() const {
        return this->Get(this->GetLength()-1);
    }

    int GetLength() const { 
	    return this->length;
	}

    void Append(T item) {
	    this->Set(this->GetLength()-1, item);
		
	}

	void Prepend(T item) {
		this->Set(0, item);
	}

	void InsertAt(T item, int index) {
		this->Set(index, item);
	}

    Vector <T>* Concat(Vector <T>* other) {
        Vector <T>* result = new Vector<T>(this->GetLength()+other->GetLength());
        for (int i = 0; i < this->GetLength(); i++)
            result->Append(this->Get(i));
        for (int i = 0; i < other->GetLength(); i++)
            result->Append(other->Get(i));
        return result;
	}

	Vector <T>* GetSubsequence(int startIndex, int endIndex) {
        if(startIndex < 0 || endIndex < 0 || startIndex >= this->GetLength() || endIndex >= this->GetLength()) {
            throw std::out_of_range("Out of range");
        }
        Vector <T>* result = new Vector<T>(this->GetLength());
        for (int i = startIndex; i <= endIndex; i++) {
            result->Append(this->Get(i));
        }
        return result;
    }

	Vector <T>* Map(T (*func)(T)) {
		Vector <T>* result = new Vector<T>(this->GetLength()); 
		for (int i = 0; i < this->GetLength(); i++) {
            result->Append(func(this->Get(i)));
        }
		return result;
	}

	Vector <T>* Where(bool (*func)(T)) {
		Vector <T>* result = new Vector<T>(this->GetLength());
		for (int i = 0; i < this->; i++) {
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

	Vector<T>* VectorAdd(const Vector<T>* other) {
		if(this->GetLength() != other->GetLength()) {
			throw std::logic_error("Lengths of vectors are not equal");
		}
		Vector<T>* result = new Vector<T>(this->GetLength());
		for(int i = 0; i < this->GetLength(); i++) {
			result->Set(i, this->Get(i) + other->Get(i));
		}
		return result;
	}

	void VectorScal(T scalar) {
		for(int i = 0; i < this->GetLength(); i++) {
			this->Set(i, this->Get(i)*scalar);
		}
	}

	T VectorNorm() {
		T result = T();
		for(int i = 0; i < this->GetLength(); i++) {
			result+=std::pow(this->GetLength(),2);
		}
		return std::sqrt(result);
	}

	T ScalarMult(const Vector<T>* other) {
		T result = T();
		for(int i = 0; i < this->GetLength(); i++) {
			result+=this->Get(i) * other->Get(i);
		}
		return result;
	}

	Sequence <T>* Slice(int index, int number, Sequence<T>* seq) {
		if(std::abs(index) > this->GetLength() || index+number > this->GetLength()) {
			throw std::out_of_range("Out of range");
		}
		Sequence <T>* result = new Vector<T>(this->GetLength());
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

	T operator[](int index) {
		if(index < 0 || index >= length ) {
			throw std::out_of_range("Out of range");
		}
		return this->data[index];
	}

	Vector<T>* operator+(const Vector<T>* other) {
		if(this->GetLength() != other->GetLength()) {
			throw std::logic_error("Lengths of vectors are not equal");
		}
		Vector<T>* result = new Vector<T>(this->GetLength());
		for(int i = 0; i < this->GetLength(); i++) {
			this->Set(i, this->Get(i) + other->Get(i));
		}
		return result;
	}

	Vector<T>& operator+(const Vector<T>& other) {
		if(this->GetLength() != other.GetLength()) {
			throw std::logic_error("Lengths of vectors are not equal");
		}
		for(int i = 0; i < this->GetLength(); i++) {
			this->Set(i, this->Get(i) + other.Get(i));
		}
		return *this;
	}
};