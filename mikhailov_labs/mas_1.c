#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *array_input(int *len) {
    printf("Elem: ");
    scanf("%d", len);
    int *data = (int *) malloc(*len * sizeof(int));
    if (!data) {
        printf("Error");
            return NULL;
        }
        for (int i = 0; i < *len; ++i) {
            data[i] = rand()%1000000;
        }
    return data;
}
void array_remove_dups(int *data, int *len) {
    for (int i = 0; i< *len-1; ++i) {
        for (int j = i+1; j<*len; ++j) {
            if (data[i] == data[j]) {
                for(int k = j; k <*len;++k) {
                    data[k]=data[k+1];
                }
                --(*len), --j;
            }
        }
    }
}

void array_print(int *len, int *data) {
        for (int i = 0; i < *len; i++) {
            printf("data[%d] = %d \n", i, data[i]);
        }
}
int main () {
    int len = 0;
    int *data = array_input(&len);
    printf("\nmas without dups\n");
    clock_t start = clock();
    array_remove_dups(data, &len);
    double end = ((double)(clock()- start)) / CLOCKS_PER_SEC;
    array_print(&len, data);
    printf("Время выполнения функции: %lf\n",end);
    return 0;
}




