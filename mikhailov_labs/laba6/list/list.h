#ifndef LIST_H
#define LIST_H

typedef struct Item {
    int data;
    struct Item *next;
} Item;

typedef struct List {
    Item *head;
    Item *tail;
} List;

List *list_new();

void list_delete(List *list);

void list_print(const List *list);

int list_push_back(List *list, int data);

int list_insert(List *list, int data);

int list_remove(List *list, int data);

#endif
