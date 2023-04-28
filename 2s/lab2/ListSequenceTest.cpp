#include <iostream>
#include "ListSequence.h"
#include <time.h>
bool func(int value) {
    return value % 2 == 0;
}

int reducer(int a, int b) {
    return 2*a + 3*b;
}

int main() {
    srand(time(nullptr));
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
    Sequence<int>* slices = seq->Slice(3,2,add);
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
    return 0;
}




    /*int data[3] = {1,2,3}; 
    Sequence<int>* list3 = new LinkedListSequence<int>(data,sizeof(data)/sizeof(int));
    for (int i = 0; i < list3->GetLength(); i++) {
        assert(list3->Get(i) == data[i]);
    }*/