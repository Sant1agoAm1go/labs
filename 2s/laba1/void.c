#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
int main () {
    srand(time(NULL));
    int lenght = 10;
    int size = sizeof(int);
    void *data = malloc(sizeof(int)*lenght);
    for(int i = 0; i < lenght; i++) {
        int value = rand() % 50;
        memcpy(data + i*size, &value, sizeof(int));
    }
    for(int i = 0; i < lenght; i++) {
        int value;
        memcpy(&value,data + i*size, sizeof(int));
        printf("data[%d] = %d\n",i, value);
    }
    return 0;
    //data->number = (*data).number
}