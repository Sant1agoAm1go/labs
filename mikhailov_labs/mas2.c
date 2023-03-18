#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *array_input(int *len) {
    printf("Elem: ");
    scanf("%d", len);
    int *data = (int *) calloc(*len, sizeof(int));
    int flag = 1;
    printf("Введите пары индекс-значение. Если хотите завершить ввод, введите -1 как индекс или как элемент\n");
    while(flag) {
        int i = 0, s = 0;
        scanf("%d %d", &i, &s);
        if (s != 0 && i<*len) {
	    if(data[i]!=0) {
	        *len = *len+1;
			data = (int*) realloc(data,*len * sizeof(int));
			for (int h = *len-1; h > i-1; h--) {
		    	data[h+1] = data[h];
			}
	    }
            data[i] = s;
        }
        if (s != 0 && i >=*len) {
        	*len = i+1;
            data = (int*) realloc(data, (*len) * sizeof(int));
            data[i] = s;
        }
        if (s == -1 || i == -1) {
            flag = 0;
        }
    }
    return data;
}
void array_print(int *len, int *data) {
        for (int k = 0; k < *len; k++) {
            printf("data[%d] = %d \n", k, data[k]);
        }
}
int main () {
    clock_t start = clock();
    int len = 0;
    int *data = array_input(&len);
    double end = ((double)(clock()- start)) / CLOCKS_PER_SEC;
    array_print(&len, data);
    printf("Время выполнения функции: %lf секунд\n",end);
    return 0;
}
