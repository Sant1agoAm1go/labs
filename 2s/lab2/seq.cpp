#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int* data = (int*) calloc(3,sizeof(int));
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    data = (int*) realloc(data, 4);
    for(int i = 3; i > 1; i--) {
        data[i] = data[i-1];
    }
    data[1] = 4;
    for(int i = 0; i < 4; i++) {
        printf("%d\n", data[i]);
    }
    printf("\n"); 
    for(int i = 2; i < 4; i++) {
        data[i] = data[i+1];
    }
    data = (int*) realloc(data, 3);
    for(int i = 0; i < 3; i++) {
        printf("%d\n", data[i]);
    }
    return 0;
}