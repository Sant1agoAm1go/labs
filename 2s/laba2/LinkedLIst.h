#pragma once
#include <iostream>
#include <cassert>
#include <stdexcept>

template <typename T> struct Item 
{
public:
    T data;
    struct Item *next;
    struct Item *prev;

};    

template <typename T> class LinkedList 
{
private:

    Item<T> *head;
    Item<T> *tail;

public:
LinkedList() {
    head = new Item<T>;
    tail = new Item<T>;

}
~LinkedList() {
    delete head;
    delete tail;
}
void LinkedList_delete(LinkedList *LinkedList) {
    Item<T> *ptr = LinkedList->head;
    while (ptr != nullptr) {
        ptr->prev = ptr;
        ptr = ptr->next;
        delete ptr->prev;
    }
    delete LinkedList;
}
void LinkedList_print(const LinkedList *LinkedList) {
    Item<T> *ptr = LinkedList->head;
    while(ptr != nullptr) {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

int LinkedList_push_back(LinkedList *LinkedList, T data) {
    Item<T> *ptr = new Item<T>;
    if (ptr == nullptr) {
        return 1;
    }
    ptr->data = data;
    ptr->next = nullptr;
    ptr->prev = nullptr;
    if (LinkedList->head == nullptr) {
        LinkedList->head = ptr;
        LinkedList->tail = ptr;
    } else {
        ptr->prev = LinkedList->tail;
        LinkedList->tail->next = ptr;
        LinkedList->tail = ptr;
    }
    return 0;
}

int LinkedList_push_begin(LinkedList *LinkedList, T data) {
	 Item<T> *ptr = new Item<T>;
	 if (ptr == nullptr) {
	 	return 1;
	 }
	 ptr->data = data;
	 ptr->next = LinkedList->head;
     ptr->prev = nullptr;
	 if(!LinkedList->head) {
	 	LinkedList->head = ptr;
	 	LinkedList->tail = ptr;
	 }
	 else {
	 	LinkedList->head = ptr; 
        //LinkedList->head->prev = nullptr;
	 }
	 return 0;
}

int LinkedList_insert(LinkedList *LinkedList, T data) {
    Item<T> *ptr = LinkedList->head;
    while (ptr!=nullptr && (ptr->data < data)) {
        ptr->prev = ptr;
        ptr = ptr->next;
    }
    Item<T> *new_Item = new Item<T>;
    if (new_Item == nullptr) {
        return 1;
    }
    new_Item->data = data;
    new_Item->next = ptr;
    new_Item->prev = nullptr;
    if (ptr->prev != nullptr) {
        ptr->prev->next = new_Item;
    } else {
        LinkedList->head = new_Item;
    }
    if (ptr == nullptr) {
        LinkedList->tail = new_Item;
    }
    return 0;
}

int LinkedList_remove(LinkedList *LinkedList, T data) {
    Item<T> *ptr = LinkedList->head;
    while (ptr != nullptr && ptr->data != data) {
        ptr->prev = ptr;
        ptr = ptr->next;
    }
    if (!ptr) {
        return 1;
    }
    if (ptr == LinkedList->head) {
        LinkedList->head = ptr->next;
    }
    if (ptr == LinkedList->tail) {
        LinkedList->tail = ptr->prev;
    }
    if (ptr->prev != nullptr) {
        ptr->prev->next = ptr->next;
    }
    delete ptr;
    return 0;
}
};
