#pragma once
#include <iostream>
#include <cassert>
#include <stdexcept>
template <typename T> struct Item {
public:
    T data;
    struct Item *next;
    struct Item *prev;

};

template <typename T> class LinkedList {
private:
    Item<T> *head;
    Item<T> *tail;
    int lenght;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        lenght = 0;
    }

    LinkedList(T* items, int count) { //	Копировать элементы из переданного массива
        head = nullptr;
        tail = nullptr;
        for (int i = 0; i < count; i++) {
            Append(items[i]);
        }
    }

    LinkedList(LinkedList <T>& list) {  // Копирующий конструктор
        head = nullptr;
        tail = nullptr;
        for (int i = 0; i < list.lenght; i++) {
            Append(list.Get(i));
        }
    }

    ~LinkedList() {
        delete head;
        delete tail;
    }

    T GetFirst() {
        if (this->head == nullptr) {
            throw std::invalid_argument("List is empty");
        }
        return this->head->data;
    }

    T GetLast() {
        if (this->head == nullptr) {
            throw std::invalid_argument("List is empty");
        }
        return this->tail->data;
    } 

    T Get(int index) {
        if(index < 0 || index >= lenght ) {
            throw std::out_of_range("Out of range");
        }
        Item<T>* ptr = this->head; 
        for(int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->data;
    } 

    int GetLenght() {
        return this->lenght;
    }

    void Append(T item) {
        Item<T> *ptr = new Item<T>;
        if (ptr == nullptr) {
            throw std::invalid_argument("Failed to allocate memory");
        }
        ptr->data = item;
        ptr->next = nullptr;
        if (this->head == nullptr) {
            this->head = ptr;
            //this->head->prev = nullptr;
            this->tail = ptr;
        } 
        else {
            ptr->prev = this->tail;
            this->tail->next = ptr;
            this->tail = ptr;
        }
        this->lenght++;
    }

    void Prepend(T item) {
        Item<T> *ptr = new Item<T>;
        if (ptr == nullptr) {
            throw std::invalid_argument("Failed to allocate memory");
        }
        ptr->data = item;
        ptr->next = this->head;
        ptr->prev = nullptr;
        if (this->head == nullptr) {
            this->head = ptr;
            //this->head->prev = nullptr;
            this->tail = ptr;
        }
        else {
            this->head->prev = ptr;
            this->head = ptr; 
        }
        (this->lenght)++;
    }

    void InsertAt(T item, int index) { 
        if(index < 0 || index >= lenght) {
            throw std::out_of_range("Out of range");
        }
        if(index == 0) {
            this->Prepend(item);
            return;
        }
        if (index == this->GetLenght()-1) {
            this->Append(item);
            return;
        }
        
        Item<T>* itemBefore = this->head; 
        for(int i = 0; i < index; i++) {
            itemBefore = itemBefore->next;
        }
        if (itemBefore == nullptr) {
            this->Append(item);
        }
        else {
            Item<T>* ptr = new Item<T>;
            /*ptr->data = item;
            ptr->prev = itemBefore;
            ptr->next = itemBefore->next;
            itemBefore->next->prev = ptr;
            itemBefore->next = ptr;*/
            ptr->data = item;
            ptr->next = itemBefore;
            ptr->prev = itemBefore->prev;
            itemBefore->prev->next = ptr;
            itemBefore->prev = ptr;
            
        }
        (this->lenght)++;
    }

    LinkedList<T>* Concat(LinkedList<T>* list) {
        for (int i = 0; i < list->lenght; i++)
            Append(list->Get(i));  
        return this;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) {
        if(startIndex < 0 || endIndex < 0 || startIndex >= lenght || endIndex >= lenght) {
            throw std::out_of_range("Out of range");
        }
        LinkedList<T>* list = new LinkedList<T>();
        for (int i = startIndex; i <= endIndex; i++) {
            list->Append(Get(i));
        }
        return list;
    }
}; 


































/*
int LinkedList_insert(LinkedList *LinkedList, T data) {
    Item<T> *ptr = LinkedList->head, *prev;
    while (ptr!=nullptr && (ptr->data < data)) {
        prev = ptr;
        ptr = ptr->next;
    }
    Item<T> *new_Item = new Item<T>;
    if (new_Item == nullptr) {
        return 1;
    }
    new_Item->data = data;
    new_Item->next = ptr;
    new_Item->prev = nullptr;
    if (prev != nullptr) {
        prev->next = new_Item;
        new_Item->prev = prev;
    } 
    else {
        LinkedList->head = new_Item;
    }
    if (ptr == nullptr) {
        LinkedList->tail = new_Item;
    }
    return 0;
}

int LinkedList_remove(LinkedList *LinkedList, T data) {
    Item<T> *ptr = LinkedList->head, *prev;
    while (ptr != nullptr && ptr->data != data) {
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
    if (prev != nullptr) {
        prev->next = ptr->next;
    }
    delete ptr;
    return 0;
}*/
