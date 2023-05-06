#pragma once
#include <cassert>
#include "Array.h"
#include "List.h"
#include "ArraySequence.h"
#include "ListSequence.h"

bool func(int value) {
    return value % 2 == 0;
}

int reducer(int a, int b) {
    return 2*a + 3*b;
}

void ArrayTest() {
    DynamicArray<int>* arr = new DynamicArray<int>(10);
    for(int i = 0; i < arr->GetSize(); i++) {
        arr->Set(i, rand () % 100);
        assert((*arr)[i] == arr->Get(i));
    }

    arr->Resize(20);
    assert(arr->GetSize() == 20); 

    DynamicArray<int>* arr2 = new DynamicArray<int>(*arr);
    for(int i = 0; i < arr->GetSize(); i++) {
        assert(arr2->Get(i) == arr->Get(i)); 
    }
    
    delete arr;
    delete arr2;
}

void ListTest() {
    LinkedList<int>* list = new LinkedList<int>();
    int lenght = 5;
    for (int i = 0; i < lenght; i++) {
        list->Append(rand() % 100);   
    }
    assert(list->GetLenght() == 5);
      for(int i = 0; i < list->GetLenght(); i++) {
        std::cout << "list[" << i << "] = " << list->Get(i) << std::endl;
    }
    lenght = list->GetLenght();
    for (int i = 0; i < lenght; i++) {
        list->Prepend(rand() % 100);
    }
 
    assert(list->GetLenght() == 10);
   
    list->InsertAt(10,7);
    assert(list->Get(7) == 10);

    LinkedList<int>* list2 = new LinkedList<int>(*list);
    assert(list2->GetLenght() == 11);
    for (int i = 0; i < list2->GetLenght(); i++) {
        assert(list2->Get(i) == list->Get(i));
    }
    int data[3] = {1,2,3}; 
    LinkedList<int>* list3 = new LinkedList<int>(data,sizeof(data)/sizeof(int));
    for (int i = 0; i < list3->GetLenght(); i++) {
        assert(list3->Get(i) == data[i]);
    }
    delete list;
    delete list2;
    delete list3;
}

void ArraySequenceTest() {
    int lenght = 10;
    //ArraySequence<int> val();
    Sequence<int>* arr = new ArraySequence<int>();
    for(int i = 0; i < lenght; i++) {
        arr->Append(rand () % 100);
    }
    
    Sequence<int>* arr2 = new ArraySequence<int>(*(ArraySequence<int>*)arr);
    for(int i = 0; i < arr2->GetLength(); i++) {
        assert(arr2->Get(i) == arr->Get(i));
    }

    Sequence<int>* concat = arr->Concat(arr2);
    for(int i = 0; i < arr->GetLength(); i++) {
        assert(concat->Get(i) == arr->Get(i));
    }

    int index = 0;
    for(int i = arr->GetLength(); i < arr2->GetLength(); i++) {
        assert(concat->Get(i) == arr2->Get(index));
        index++;
    }

    Sequence<int>* subs = concat->GetSubsequence(5,15);
    for(int i = 0; i < subs->GetLength(); i++) {
        assert(subs->Get(i) == concat->Get(i+5));
    }

    Sequence<int>* wheres = subs->Where(func);

    for(int i = 0; i < wheres->GetLength(); i++) {
        assert(func(wheres->Get(i)) == true);
    }
    
    int data[3] = {1,2,3};
    int data2[5] = {1,2,3,4,5};
    int data3[2] = {9,10};
    Sequence<int>* reduce_check = new ArraySequence<int>(data,sizeof(data)/sizeof(int));
    assert(reduce_check->Reduce(reducer, 4) == 144);

    Sequence<int>* seq = new ArraySequence<int>(data2,sizeof(data2)/sizeof(int));
    Sequence<int>* add  = new ArraySequence<int>(data3,sizeof(data3)/sizeof(int));
    Sequence<int>* slices = seq->Slice(1,2,add);
    for(int i = 0; i < slices->GetLength(); i++) {
        std::cout << "slices[" << i << "] = " << slices->Get(i) << std::endl;
    }

    delete arr;
    delete arr2; 
    delete concat;
    delete subs;
    delete wheres;
    delete reduce_check;
    delete seq;
    delete add;
    delete slices;
}

void ListSequenceTest() {
    int lenght = 10;
    Sequence<int>* list = new LinkedListSequence<int>();
    for(int i = 0; i < lenght; i++) {
        list->Append(rand () % 100);
    }
    
    Sequence<int>* list2 = new LinkedListSequence<int>(*(LinkedListSequence<int>*)list);
    for(int i = 0; i < list2->GetLength(); i++) {
        assert(list2->Get(i) == list->Get(i));
    }

    Sequence<int>* concat = list->Concat(list2);
    for(int i = 0; i < list->GetLength(); i++) {
        assert(concat->Get(i) == list->Get(i));
    }

    int index = 0;
    for(int i = list->GetLength(); i < list2->GetLength(); i++) {
        assert(concat->Get(i) == list2->Get(index));
        index++;
    }

    Sequence<int>* subs = concat->GetSubsequence(5,15);
    for(int i = 0; i < subs->GetLength(); i++) {
        assert(subs->Get(i) == concat->Get(i+5));
    }

    Sequence<int>* wheres = subs->Where(func);

    for(int i = 0; i < wheres->GetLength(); i++) {
        assert(func(wheres->Get(i)) == true);
    }
    
    int data[3] = {1,2,3};
    int data2[5] = {1,2,3,4,5};
    int data3[2] = {9,10};
    Sequence<int>* reduce_check = new LinkedListSequence<int>(data,sizeof(data)/sizeof(int));
    assert(reduce_check->Reduce(reducer, 4) == 144);

    Sequence<int>* seq = new LinkedListSequence<int>(data2,sizeof(data2)/sizeof(int));
    Sequence<int>* add  = new LinkedListSequence<int>(data3,sizeof(data3)/sizeof(int));
    Sequence<int>* slices = seq->Slice(1,2,add);
    for(int i = 0; i < slices->GetLength(); i++) {
        std::cout << "slices[" << i << "] = " << slices->Get(i) << std::endl;
    }

    Sequence<int>* list3 = new LinkedListSequence<int>(data,sizeof(data)/sizeof(int));
    for (int i = 0; i < list3->GetLength(); i++) {
        assert(list3->Get(i) == data[i]);
    }
    delete list;
    delete list2; 
    delete list3;
    delete concat;
    delete subs;
    delete wheres;
    delete reduce_check;
    delete seq;
    delete add;
    delete slices;

}