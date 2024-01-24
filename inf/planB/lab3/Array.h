#include "Laba3.h"

template <class T> class DynamicArray
{
private:
    int count;
    T* items;
    //int* flags; //1-item set 0 - item not set 

public:
    DynamicArray(T* items, int count)
    {
        this->count = count;
        this->items = new T[count];

        for (int i = 0; i < count; i++)
        {
            this->items[i] = move(items[i]);
        }
        return;
    }

    DynamicArray(T* items, int count, int capacity)
    {
        this->count = count;
        this->items = new T[capacity];

        for (int i = 0; i < count; i++)
        {
            //this->items[i] = move(items[i]);
            this->items[i] = (items[i]);
        }
        return;
    }

    DynamicArray(int size)
    {
        this->count = size;
        this->items = new T[count];

        //        for (int i = 0; i < count; i++)
        //        {
        //            this->items[i] = nullptr;
        //            this->items[i] = 0;
        //        }

        return;
    }

    DynamicArray(const DynamicArray<T>& dynamicArray)
    {
        this->count = dynamicArray.count;
        this->items = new T[this->count];

        for (int i = 0; i < this->count; i++)
        {
            this->items[i] = dynamicArray.items[i];
        }

        return;
    }

    ~DynamicArray()
    {
        if (items != nullptr)
        {
            delete[] items;
            items = nullptr;
        }
        return;
    }

    void print(int count) const
    {
        cout << "count=" << count << endl;
        for (int i = 0; i < count; i++)
        {
            //cout << "; [" << i << "]=" << this->items[i].get();
            //cout << "; [" << i << "]=" << this->items[i];
            cout << "[" << i << "]=" << this->items[i] << endl;
        }
        cout << endl;
        return;
    }

    int GetSize()
    {
        return this->count;
    }

    T& Get(int index)
    {
        if (index < 0) throw index;
        if (index >= this->GetSize()) throw index;
        return this->items[index];
    }
    /*
    void Set(int index, T value)
    {
        if (index < 0) throw index;
        if (index >= this->GetSize()) throw index;
        this->items[index] = value;
        return;
    }
    */
    void Set(int index, T value)
    {
        if (index < 0) throw index;
        if (index >= this->GetSize()) throw index;
        this->items[index] = move(value);
        return;
    }

    void SetCount(int count)
    {
        this->count = count;
        return;
    }

    void Resize(int newSize)
    {
        if (newSize < 0) return; //no change
        T* newItems = new T[newSize];
        int count = this->count;
        if (this->count > newSize) count = newSize;

        for (int i = 0; i < count; i++)
        {
            newItems[i] = move(this->items[i]);
        }

        delete[] this->items;
        this->items = newItems;
        this->count = count;

        //printf("HERE RESIZE\n");
        return;
    }


};


template <class T> class ArraySequence : public Sequence<T>
{
private:
    int count;
    int capacity;
    DynamicArray<T>* items;

public:
    ArraySequence(T* items, int count)
    {
        this->count = count;
        this->capacity = this->count * 2;
        this->items = new DynamicArray<T>{ items,  this->count, this->capacity };
        return;
    }

    ArraySequence()
    {
        this->count = 0;
        this->capacity = 10000;
        this->items = new DynamicArray<T>{ this->capacity };
        return;
    }

    ArraySequence(LinkedList <T>& list) //const?
    {

        this->count = list.GetLength();
        this->capacity = this->count * 2;
        this->items = new DynamicArray<T>{ this->capacity };
        for (int i = 0; i < this->count; i++)
        {
            this->items->Set(i, list.Get(i));
        }
        this->items->SetCount(this->capacity);
        return;
    }

    ~ArraySequence()
    {
        //printf("HERE_ARRAY"); 
        if (items != NULL) { delete items; items = NULL; };
        return;
    }

    void print() const override
    {
        this->items->print(this->count);
        return;
    }

    T& GetFirst() const override
    {
        return this->items->Get(0);
    }

    T& GetLast() const override
    {
        return this->items->Get(this->count - 1);
    }

    T& Get(int index) const override
    {
        if (index < 0) throw index;
        if (index >= this->count) throw index;

        return this->items->Get(index);
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        if (startIndex < 0) throw startIndex;
        if (startIndex >= this->count) throw startIndex;
        if (endIndex < 0) throw endIndex;
        if (endIndex >= this->count) throw endIndex;
        if (startIndex > endIndex) throw (string)"startIndex > endIndex";

        Sequence <T>* newArray = new ArraySequence <T>{ };

        for (int i = startIndex; i <= endIndex; i++)
        {
            newArray->Append((this->items->Get(i)));
            newArray->Append((this->items->Get(i)));
        }

        return newArray;
    }

    int GetLength() const override
    {
        return this->count;
    }

    void Append(T& item) override
    {
        if (this->count >= this->capacity)
        {
            this->capacity *= 2;
            this->items->Resize(this->capacity);
        }
        this->items->SetCount(this->items->GetSize() + 1);
        this->items->Set(this->count, move(item));
        this->count++;

        return;
    }

    void Prepend(T& item) override
    {

        if (this->count >= this->capacity)
        {
            this->capacity *= 2;
            this->items->Resize(this->capacity);
        }

        this->items->SetCount(this->items->GetSize() + 1);

        for (int i = this->count; i > 0; i--)
        {
            this->items->Set(i, move(this->items->Get(i - 1)));
        }
        this->items->Set(0, move(item));
        this->count++;
        return;
    }

    void InsertAt(T& item, int index) override
    {
        if (index < 0) throw index;
        if (index >= this->GetLength()) throw index;

        if (this->count >= this->capacity)
        {
            this->capacity *= 2;
            this->items->Resize(this->capacity);
        }

        this->items->SetCount(this->items->GetSize() + 1);

        for (int i = this->count; i > index; i--)
        {
            this->items->Set(i, move(this->items->Get(i - 1)));
        }

        this->items->Set(index, move(item));
        this->count++;
        return;
    }

    void DelItem(int index) override
    {
        if (index < 0) throw index;
        if (index >= this->GetLength()) throw index;

        //this->items->Get(index).~SmartPtr();


        for (int j = index; j < this->count - 1; j++)
        {
            this->items->Set(j, move(this->Get(j + 1)));
        }

        this->items->SetCount(this->items->GetSize() - 1);
        this->count--;

        if (this->count <= this->capacity / 2)
        {
            this->capacity /= 2;
            this->items->Resize(this->capacity);
        }

        return;
    }

    Sequence <T>* Concat(Sequence <T>* list) override
    {
        for (int i = 0; i < list->GetLength(); i++)
        {
            this->Append(list->Get(i));
        }
        return (Sequence <T>*)this;
    }

    Sequence<T>* ShellSort(bool (*cmp)(T, T)) override
    {
        int n = this->count;
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                T temp = this->items->Get(i);
                int j;
                for (j = i; j >= gap && cmp(this->items->Get(j - gap), temp); j -= gap) {
                    this->items->Set(j, this->items->Get(j - gap));
                }
                this->items->Set(j, temp);
            }
        }
        return (Sequence<T>*) this;
    }
    /*
    Sequence<T>* ShellSort(bool (*cmp)(T, T)) override
    {
        int length = this->count;
        int gap = length / 2;
        while (gap > 0) {
            for (int i = gap; i < length; i++) {
                T temp = this->items->Get(i);
                T j = i;
                while (j >= gap && cmp(this->items->Get(j - gap), temp)) {
                    this->items->Set(j, this->items->Get(j - gap));
                    j -= gap;
                }
                this->items->Set(j, temp);
            }
            gap /= 2;

        }
        return (Sequence<T>*)this;
    }
    */
   

    
    
    Sequence<T>* QuickSort(bool (*cmp1)(T, T), bool (*cmp2)(T, T), int left, int right) override
    {
        int i = left, j = right;
        T tmp;
        T pivot = this->items->Get((left + right) / 2);


        while (i <= j) {
            while (cmp1(this->items->Get(i), pivot))
                i++;
            while (cmp2(this->items->Get(j),pivot))
                j--;
            if (i <= j) {
                tmp = this->items->Get(i);
                this->items->Set(i, this->items->Get(j));
                this->items->Set(j, tmp);
                i++;
                j--;
            }
        };

        if (left < j)
            QuickSort(cmp1, cmp2, left, j);
        if (i < right)
            QuickSort(cmp1, cmp2, i, right);
        return (Sequence<T>*)this;
    }
    
    Sequence<T>* SelectionSort(bool (*cmp)(T, T)) override
    {
        int i, j, min_idx;
        int n = this->count;
        for (i = 0; i < n - 1; i++) {
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
                if (cmp(this->items->Get(j), this->items->Get(min_idx))) {
                    min_idx = j;
                }
            }
            T tmp = this->items->Get(min_idx);
            this->items->Set(min_idx, this->items->Get(i));
            this->items->Set(i, tmp);
            //swap(&arr[min_idx], &arr[i]);
        }
        return (Sequence<T>*)this;
    }

    virtual T& operator[] (int index) override
    {
        if (index < 0) throw index;
        if (index >= this->GetLength()) throw index;

        return this->items->Get(index);
    }
};
