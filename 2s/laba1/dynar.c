#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynar.h"
DynamicArray* create_DynamicArray(size_t size_of_type, size_t lenght) {
    DynamicArray* result = NULL;
    result = malloc(sizeof(DynamicArray)); //Выделение памяти под структуру.
    result->size_of_type = size_of_type;
    result->lenght = lenght;
    result->data = malloc(sizeof(void *) * lenght); // Выделение памяти под массив указателей (контейнер указателей)
    //Создание пустого динамического массива.
    for (size_t i = 0; i < lenght; i++) {
        result->data[i] = malloc(result->size_of_type); //Выделение памяти под отдельный элемент.
    }
    return result;
}

void fill_random_DynamicArray(DynamicArray* dynArr) { //Заполнение случайными числами;
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
    }
}

void create_definite_DynamicArray(DynamicArray* dynArr) {
    switch(dynArr->size_of_type) {
        case sizeof(int):
            for(size_t i = 0; i < dynArr->lenght; i++) {
		        scanf("%d",dynArr->data[i]);
	        }
            break;
        case sizeof(double):
            for(size_t i = 0; i < dynArr->lenght; i++) {
		        scanf("%lf",dynArr->data[i]);
	        }
            break;
    }
}

void delete_DynamicArray(DynamicArray* dynArr) {
    for (size_t i = 0; i < dynArr->lenght; i++) {
        free(dynArr->data[i]); //Освобождение памяти, выделенной под каждый элемент.
    }
    free(dynArr->data); //Освобождение памяти, выделенной под массив указателей.
    free(dynArr);
}

void DynamicArray_set(DynamicArray* dynArr, void* value, size_t index) {
    memcpy(dynArr->data[index], value, dynArr->size_of_type);
}

void* DynamicArray_get(DynamicArray* dynArr, size_t index) {
    void *value = malloc(dynArr->size_of_type);
    memcpy(value, dynArr->data[index], dynArr->size_of_type);
    return value;
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
    }    
}
