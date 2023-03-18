#include <stdio.h>
#include <stdlib.h>
#include "zag3.h"
int main () {
    double s = 0;
    int len = 0, len_true = 0, input = 0, error = 0;
    double *data = NULL, *data2 = NULL;
    while(1) {
		printf("Список функций:\n");
        printf("1 - инициализация массива\n");
        printf("2 - вывод текущего состояния массива\n");
		printf("3 - индивидуальное задание\n");
        printf("4 - вставка элемента по индексу\n");
        printf("5 - удаление элемента по индексу\n" );
        printf("6 - добавление количества элементов\n");
        printf("0 - выход из программы\n");
        error = check_int(&input);
        if (error == 1) {
            break;
        }
        if(input == 1) {
            free(data);
            error = array_input1(&len,&len_true, &s, &data);
            if(error == 1) {
                break;
            }
        }
        if (input == 2) {
            array_print(len, len_true, data, s);
        }
        if (input == 3) {
            if (len_true > 0) {
            free(data2);
            data2 = array_input2(&len_true,&s,data);
            printf("\nfirst mas:\n");
            array_print(len, len_true, data, s);
            printf("\nsecond mas:\n");
            array_print(len, len_true,data2, s);
            data = array_remove(&len,&len_true,&data,&s);
            printf("\nfirst mas without wrong numbers:\n");
            array_print(len, len_true,data, s);
            }
            else {
                printf("Нет элементов в первом массиве!\n");
            }
        }
        if (input == 4) {
           error = array_insert(&len, &len_true, &data, &s);
           if (error == 1) {
               break;
           }
        }
        if (input == 5) {
            error = array_remove2(&len,&len_true, &data, &s);
            if (error == 1) {
               break;
            }
        }
        if (input == 6){
            error = array_add(&len, &data);
            if (error == 1) {
                break;
            }
        }
        if(input == 0) {
            break;
        }
    }
    free(data);
    free(data2);
    return 0;
}
