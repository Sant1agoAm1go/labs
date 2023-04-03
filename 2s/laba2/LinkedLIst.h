#pragma once
#include <iostream>
#include <cassert>
#include <stdexcept>
template <typename T> class LinkedList 
{
private:
    Item *head;
    Item *tail;

public:
LinkedList() {
    head = new Item[1];
    tail = new Item[1];

}
void LinkedList_delete(LinkedList *LinkedList) {
    Item *ptr = LinkedList->head, *prev;
    while (ptr) {
        prev = ptr;
        ptr = ptr->next;
        delete prev;
    }
    delete LinkedList;
}
void LinkedList_print(const LinkedList *LinkedList) {
    Item *ptr = LinkedList->head;
    while (ptr) {
        std::cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int LinkedList_push_back(LinkedList *LinkedList, T data) {
    Item *ptr = (Item *) malloc(sizeof(Item));
    if (!ptr) {
        return 1;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (!LinkedList->head) {
        LinkedList->head = ptr;
        LinkedList->tail = ptr;
    } else {
        LinkedList->tail->next = ptr;
        LinkedList->tail = ptr;
    }
    return 0;
}

int LinkedList_push_begin(LinkedList *LinkedList, T data) {
	 Item *ptr = (Item *) malloc(sizeof(Item));
	 if (!ptr) {
	 	return 1;
	 }
	 ptr->data = data;
	 ptr->next = LinkedList->head;
	 if(!LinkedList->head) {
	 	LinkedList->head = ptr;
	 	LinkedList->tail = ptr;
	 }
	 else {
	 	LinkedList->head = ptr; 
	 }
	 return 0;
}

int LinkedList_insert(LinkedList *LinkedList, T data) {
    Item *ptr = LinkedList->head, *prev;
    while (ptr && (ptr->data < data)) {
        prev = ptr;
        ptr = ptr->next;
    }
    Item *new_item = (Item *) malloc(sizeof(Item));
    if (!new_item) {
        return 1;
    }
    new_item->data = data;
    new_item->next = ptr;
    if (prev) {
        prev->next = new_item;
    } else {
        LinkedList->head = new_item;
    }
    if (!ptr) {
        LinkedList->tail = new_item;
    }
    return 0;
}

int LinkedList_remove(LinkedList *LinkedList, T data) {
    Item *ptr = LinkedList->head, *prev;
    while (ptr && ptr->data != data) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (!ptr) {
        return 1;
    }
    if (ptr == LinkedList->head) {
        LinkedList->head = ptr->next;
    }
    if (ptr == LinkedList->tail) {
        LinkedList->tail = prev;
    }
    if (prev) {
        prev->next = ptr->next;
    }
    delete ptr;
    return 0;
}
};

template <typename T> class Item 
{
    private:
    T data;
    class Item *next;
};
