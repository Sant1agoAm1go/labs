#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "zag.h"

struct Args {
	int data;
	int len;
};

int *array_input (int *len) {
    printf("Elem: ");
    scanf("%d", len);
    int *data = (int *) malloc(*len * sizeof(int));
    if (!data) {
        printf("Error");
            return NULL;
        }
        for (int i = 0; i < *len; i++) {
            data[i] = rand() % 100;
        }
    return data;
}

void get_func (void *args){
	struct Args *hell = (struct Args *)args;
	int data = hell->data;
	int len = hell->len;
	for (int i = 0; i < len; i ++){
		printf("%d\n", data);
	}
}

int *array_remove_dups(int *data, int *len) {
	int len2 = 0;
    int *data2 = (int *) calloc(*len, sizeof(int));
    for (int i = 0; i < *len; i++) {
		int j = 0;
        for (j = 0; j < len2; j++) {
            if (data2[j] == data[i]) {
                break;
			}
		}
		if(j == len2) {
			data2[len2] = data[i];
			len2 ++;
		}
	}
	*len = len2;
	return data2;
}

void array_print(int len, int *data2) {
    for (int i = 0; i < len; i++) {
		printf("data[%d] = %d \n", i, data2[i]);
	}		
}

int main () {
    int len = 0;
    //int *data = array_input(&len);
    int data = 123;
    struct Args *arg;
    arg->data = data;
    arg->len = len;
    double end = count_time (arg);
	//data = array_remove_dups(data, &len);
    printf("\nmas without dups\n");
    //array_print(len, data);
    printf("Время выполнения функции: %lf секунд",end);
    //free(data);
    return 0;
}
