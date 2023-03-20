#include <stdio.h>
#include <stdlib.h>
#include "dynar.h"
DynamicArray* create_DynamicArray(size_t size_of_type, size_t lenght) {
    DynamicArray* result = NULL;
    result = malloc(sizeof(DynamicArray)); //Выделение памяти под структуру.
    result->size_of_type = size_of_type;
    result->lenght = lenght;
    result->data = malloc(sizeof(void *) * lenght); // Выделение памяти под массив указателей (контейнер указателей)
    //Создание пустого динамического массива.
    for (size_t i = 0; i < lenght; i++) {
        result->data[i] = malloc(sizeof(void *)); //Выделение памяти под отдельный элемент.
    }
    return result;
}

void fill_DynamicArray(DynamicArray* dynArr) { //Заполнение случайными числами;
    switch(dynArr->size_of_type) {
        case sizeof(int):
            for(size_t i = 0; i < dynArr->lenght; i++) {
		        *(int*)(dynArr->data[i]) = rand() % 50;
	        }
            break;
        case sizeof(double):
            for(size_t i = 0; i < dynArr->lenght; i++) {
		        *(double*)(dynArr->data[i]) = rand() % 50;
	        }
            break;
        default: 
            //printf("Impossible to fill the array\n"); 

    }
}

void delete_DynamicArray(DynamicArray* dynArr) {
    for (size_t i = 0; i < dynArr->lenght; i++) {
        free(dynArr->data[i]); //Освобождение памяти, выделенной под каждый элемент.
    }
    free(dynArr->data); //Освобождение памяти, выделенной под массив указателей.
    free(dynArr);
}

void some_printf(DynamicArray* dynArr) {
    switch (dynArr->size_of_type) {
        case sizeof(int):
            for (size_t i = 0; i < dynArr->lenght; i++) {
                printf("a[%ld] = %d\n", i, *(int*)(dynArr->data[i]));
            }
            break;
        case sizeof(double):
            for (size_t i = 0; i < dynArr->lenght; i++) {
                printf("a[%ld] = %f\n", i, *(double*)(dynArr->data[i]));
            }
            break;
        default:
            //printf("This data type is not supported by the function some_printf\n");
    }    
}
