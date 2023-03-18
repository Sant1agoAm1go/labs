#include <stdio.h>

#include "queue.h"

int main() {
    Queue *q = queue_new();
    for (int i = 1; i <= 10; ++i) {
        queue_put(q, i);
        queue_print(q);
    }
    printf("\n");
    int data;
    while (!queue_get(q, &data)) {
        printf("(%d) ", data);
        queue_print(q);
    }
    queue_delete(q);
    return 0;
}
