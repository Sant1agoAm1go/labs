#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

Stack *stack_new() {
    return (Stack *) calloc(1, sizeof(Stack));
}

void stack_delete(Stack *stack) {
    Item *ptr = stack->head, *ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(stack);
}

int stack_push(Stack *stack, int data) {
    Item *new = (Item *) malloc(sizeof(Item));
    if (!new) {
        return 1;
    }
    new->data = data;
    new->next = stack->head;
    stack->head = new;
    return 0;
}

int stack_pop(Stack *stack, int *output) {
    if (!stack->head) {
        return 1;
    }
    *output = stack->head->data;
    Item *head = stack->head;
    stack->head = head->next;
    free(head);
    return 0;
}

void stack_print(const Stack *stack) {
    Item *ptr = stack->head;
    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
