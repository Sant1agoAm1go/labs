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
        printf("3 - вставка элемента по индексу\n");
        printf("4 - удаление элемента по индексу\n" );
        printf("5 - индивидуальное задание\n");
        printf("6 - добавить количество элементов\n");
        printf("0 - выйти из программы\n");
        error = check_int(&input);
        if (error == 1){
            break;
        }

        switch(input) {
            case 1:
            	free(data);
                error = array_input1(&len,&len_true, &s, &data);
                if(error == 1) {
                    break;
                }
                break;
            case 2:
                array_print(len,len_true, data, s);
                break;
            case 3:
                error = array_insert(&len, &len_true, &data, &s);
                if (error == 1) {
                    break;
                }
                break;

            case 5:
            	if (len_true > 0) {
            	free(data2);
                data2 = array_input2(&len_true,&s,data);
                printf("\nfirst mas:\n");
                array_print(len,len_true, data, s);
                printf("\nsecond mas:\n");
                array_print(len, len_true,data2, s);
                data = array_remove(&len,&len_true,&data,&s);
                printf("\nfirst mas without wrong numbers:\n");
                array_print(len, len_true, data, s);
                }
				else {
					printf("Нет элементов в первом массиве!\n");
				}           
                break;

            case 4:
                error = array_remove2(&len,&len_true, &data, &s);
                if (error == 1) {
                    break;
                }
                break;

            case 6:
            	error = array_add(&len, &data);
            	if (error == 1) {
                	break;
            	}
            	break;
            
            case 0:
            	free(data);
            	free(data2);
            	return 0;
            default:
            	printf("Введите номер из списка!\n");
        }
    }
    free(data);
    free(data2);
    return 0;
}
