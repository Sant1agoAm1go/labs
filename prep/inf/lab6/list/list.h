#ifndef LIST_H
#define LIST_H

typedef struct Item {
    char ch;
    struct Item *next;
    struct Item *prev;
} Item;

typedef struct List {
    Item *head;
    Item *tail;
} List;

List *list_new();

void list_delete(List *list);

void list_print(const List *list);

int list_push_back(List *list, char ch);

int list_push_begin(List *list, char ch);

int list_insert(List *list, char ch);

int list_remove(List *list, char ch);

#endif
