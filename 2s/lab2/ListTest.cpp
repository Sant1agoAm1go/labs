#include <iostream>
#include "List.h"
#include <time.h>
int main() {
    srand(time(nullptr));
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
    return 0;
}