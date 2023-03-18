#include <stdio.h>

#include "stack.h"

int main() {
    Stack *s = stack_new();
    for (int i = 1; i <= 10; ++i) {
        stack_push(s, i);
        stack_print(s);
    }
    printf("\n");
    int data;
    while (!stack_pop(s, &data)) {
        printf("(%d) ", data);
        stack_print(s);
    }
    stack_delete(s);
    return 0;
}
