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
    
    delete list;
    delete list2;
    return 0;
}