#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List *list_new() {
    return (List *) calloc(1, sizeof(List));
}

void list_delete(List *list) {
    Item *ptr = list->head, *prev;
    while (ptr) {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    free(list);
}

void list_print(const List *list) {
    Item *ptr = list->head;
    while (ptr) {
        switch(ptr->size) {
            case sizeof(int):
            printf("%d", *(int*)(ptr->data));
            break;
            ptr = ptr->next;
        }
    }
}

int list_push_back(List *list, void *data) {
    Item *ptr = (Item *) malloc(sizeof(Item));
    if (!ptr) {
        return 1;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (!list->head) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        list->tail->next = ptr;
        list->tail = ptr;
    }
    return 0;
}

int list_push_begin(List *list, void* data) {
	 Item *ptr = (Item *) malloc(sizeof(Item));
	 if (!ptr) {
	 	return 1;
	 }
	 ptr->data = data;
	 ptr->next = list->head;
	 if(!list->head) {
	 	list->head = ptr;
	 	list->tail = ptr;
	 }
	 else {
	 	list->head = ptr; 
	 }
	 return 0;
}

int list_insert(List *list, void *data) {
    Item *ptr = list->head, *prev;
    while (ptr && (ptr->data < data)) {
        prev = ptr;
        ptr = ptr->next;
    }
    Item *new = (Item *) malloc(sizeof(Item));
    if (!new) {
        return 1;
    }
    new->data = data;
    new->next = ptr;
    if (prev) {
        prev->next = new;
    } else {
        list->head = new;
    }
    if (!ptr) {
        list->tail = new;
    }
    return 0;
}

int list_remove(List *list, void* data) {
    Item *ptr = list->head, *prev;
    while (ptr && ptr->data != data) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (!ptr) {
        return 1;
    }
    if (ptr == list->head) {
        list->head = ptr->next;
    }
    if (ptr == list->tail) {
        list->tail = prev;
    }
    if (prev) {
        prev->next = ptr->next;
    }
    free(ptr);
    return 0;
}
