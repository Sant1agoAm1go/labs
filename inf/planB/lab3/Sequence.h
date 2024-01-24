#include "Laba3.h"

template <class T> class Sequence
{
public:
    virtual void print() const = 0;
    virtual T& GetFirst() const = 0;
    virtual T& GetLast() const = 0;
    virtual T& Get(int index) const = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int  GetLength() const = 0;
    virtual void Append(T& item) = 0;
    virtual void Prepend(T& item) = 0;
    virtual void InsertAt(T& item, int index) = 0;
    virtual void DelItem(int index) = 0;
    virtual Sequence <T>* Concat(Sequence <T>* list) = 0;
    virtual Sequence<T>* ShellSort(bool (*cmp)(T, T)) = 0;
    virtual Sequence<T>* QuickSort(bool (*cmp1)(T, T), bool (*cmp2)(T, T), int left, int right) = 0;
    virtual Sequence<T>* SelectionSort(bool (*cmp)(T, T)) = 0;
    virtual T& operator[] (int index) = 0;
};