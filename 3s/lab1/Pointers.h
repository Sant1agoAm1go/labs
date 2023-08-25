#pragma once 
#include <iostream>
#include <stdexcept>
template <typename T>
class UnqPtr {
    private:
        T* ptr;

    public:
        UnqPtr() {
            ptr = nullptr;
        }

        UnqPtr(UnqPtr<T>&& other) {
            this->ptr = other.ptr;
            other.ptr = nullptr;
        }

        UnqPtr(T* other) {
            this->ptr = other;

        }

        ~UnqPtr() {
            std::cout << "Deleting unique pointer..." << std::endl;
            delete[] ptr; 
        }

        T* Release() {
            T* tmp = this->ptr;
            this->ptr = nullptr;
            return tmp;
        }

        void Reset() {
            delete ptr;
        }

        void Swap(UnqPtr<T>& other) {
            T* tmp = this->ptr;
            this->ptr = other.ptr;
            other.ptr = tmp;
        }

        T* Get() {
            return this->ptr;
        }

        UnqPtr<T>& operator=(UnqPtr<T>&& other) {
            this->ptr = other.ptr;
            other.ptr = nullptr;
            return *this;
        }

        UnqPtr<T>& operator=(T* other) {
            this->ptr = other;
            return *this;
        }

        operator bool() {
            return this->ptr;
        }

        T& operator*() {
            return *(this->ptr);
        }

        T* operator->() {
            return this->ptr;
        }

        T& operator[](int index) {
            if(index < 0) {
			    throw std::out_of_range("Out of range");
	        }
		    return this->ptr[index];
	    }
};

template <typename T> 
class ShrdPtr {
    private:
        T* ptr;
        int* counter;
    public:
    ShrdPtr() {
        this->ptr = nullptr;
        this->counter = nullptr;
    }

    ShrdPtr(const ShrdPtr<T>& other) {
        this->ptr = other.ptr;
        this->counter = other.counter;
        (*this->counter)++;
    }

    ShrdPtr(T* other) {
        this->ptr = other;
        this->counter = new int(1);
    }

    ~ShrdPtr() {
        if(counter) {
            (*counter)--;
            if(*counter <= 0) {
                //std::cout << "Deleting shared pointer..." << std::endl;
                delete[] ptr; 
                delete counter;
            }
        }
    }

    int UseCount() {
        return *this->counter;
    }

    bool Unique() {
        return *this->counter == 1;
    }

    void Reset() {
        if(counter) {
            (*counter)--;
            if(*counter <= 0) {
                std::cout << "Deleting shared pointer..." << std::endl;
                delete ptr; 
                delete counter;
            }
        }
        this->ptr = nullptr;
        this->counter = nullptr;
    }

    void Swap(UnqPtr<T>& other) {
        T* tmp = this->ptr;
        int* tmp_counter = this->counter; 
        this->ptr = other.ptr;
        other.ptr = tmp;
        this->counter = other.counter;
        other.counter = tmp_counter;
    }

    T* Get() {
        return this->ptr;
    }

    ShrdPtr<T>& operator=(const ShrdPtr<T>& other) {
        if(counter) {
            (*counter)--;
            if(*counter <= 0) {
                std::cout << "Deleting shared pointer..." << std::endl;
                delete ptr; 
                delete counter;
            }
        }
        this->ptr = other.ptr;
        this->counter = other.counter;
        (*this->counter)++;
        return *this;
    }

    ShrdPtr<T>& operator=(T* other) {
        if(counter) {
            (*counter)--;
            if(*counter <= 0) {
                std::cout << "Deleting shared pointer..." << std::endl;
                delete ptr; 
                delete counter;
            }
        }
        this->ptr = other;
        this->counter = new int(1);
        return *this;
    }

    operator bool() {
        return this->ptr;
    }

    T& operator*() {
        return *(this->ptr);
    }

    T* operator->() {
        return this->ptr;
    }

    T& operator[](int index) {
        if(index < 0) {
            throw std::out_of_range("Out of range");
        }
        return this->ptr[index];
    }

};

/*template <typename T> 
class WeakPtr {
    private:
        ShrdPtr<T>& ptr;
    public:

        WeakPtr() {};

        ~WeakPtr() {};

};*/

template <typename T> 
class WeakPtr {
    private:
        T* ptr;
    public: 
        WeakPtr() {
            ptr = nullptr;
        }

        WeakPtr(const WeakPtr<T>& other) {
            this->ptr = other.ptr;
        }

        ~WeakPtr() {
            std::cout << "Deleting weak pointer..." << std::endl;
            delete ptr;
        }

        void Reset() {
            delete ptr;
        }

        void Swap(WeakPtr<T>& other) {
            T* tmp = this->ptr;
            this->ptr = other.ptr;
            other.ptr = tmp;
        }

        void Expired() {
            return this->ptr == nullptr;
        }

        WeakPtr<T>& operator=(const WeakPtr<T>& other) {
            this->ptr = other.ptr;
            return *this;
        }    
};
