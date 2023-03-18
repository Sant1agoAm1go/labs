#ifndef STACK_H
#define STACK_H

typedef struct Item {
    int data;
    struct Item *next;
} Item;

typedef struct Stack {
    Item *head;
} Stack;

Stack *stack_new();

void stack_delete(Stack *stack);

int stack_push(Stack *stack, int data);

int stack_pop(Stack *stack, int *output);

void stack_print(const Stack *stack);

#endif
