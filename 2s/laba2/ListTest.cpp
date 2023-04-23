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
    std::cout << list->GetLenght() << std::endl;
    list->InsertAt(10,7);
    assert(list->Get(7) == 10);
    std::cout << "\n";
    for (int i = 0; i < list->GetLenght(); i++) {
        std::cout << list->Get(i) << std::endl;
    }
    std::cout << "\n";
    LinkedList<int>* list2 = new LinkedList<int>(*list);
    for (int i = 0; i < list2->GetLenght(); i++) {
        std::cout << list2->Get(i) << std::endl;
    }
    delete list;
    return 0;
}