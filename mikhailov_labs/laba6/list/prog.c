#include "list.h"

int main() {
    List *l = list_new();
    list_insert(l, 10);
    list_print(l);
    list_insert(l, 20);
    list_print(l);
    list_insert(l, 30);
    list_print(l);
    list_push_back(l, 40);
    list_print(l);
    list_insert(l, 35);
    list_print(l);
    list_insert(l, 5);
    list_print(l);
    list_remove(l, 20);
    list_print(l);
    list_push_back(l, 45);
    list_print(l);
    list_delete(l);
    return 0;
}
