#ifndef LIST_H
#define LIST_H

typedef struct Item {
    void *data;
    int size;
    struct Item *next;
} Item;

typedef struct List {
    Item *head;
    Item *tail;
} List;

List *list_new();

void list_delete(List *list);

void list_print(const List *list);

int list_push_back(List *list, void *data);

int list_push_begin(List *list, void *data);

int list_insert(List *list, void *data);

int list_remove(List *list, void *data);

#endif
