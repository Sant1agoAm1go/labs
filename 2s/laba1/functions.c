#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "functions.h"
#include "dynar.h"

void check_int(int *input) {
	int check = 0;
	while(check != 1) {
		check = scanf("%d", input);
		if (check == 1) {
			break;
		}
		printf("You entered uncorrect data! Please, enter the number!\n");
		scanf("%*[^\n]"); 
	}
}

void swap(DynamicArray* dynArr, int i, int j) {
	void* temp = dynArr->data[i];
	dynArr->data[i] = dynArr->data[j];
	dynArr->data[j] = temp;
}

int cmp_int(const void *p1, const void *p2) {
	int* value1 = (int*) p1;
	int* value2 = (int*) p2;
	return *value1 - *value2;  	
}

int cmp_int_rev(const void *p1, const void *p2) {
	int* value1 = (int*) p1;
	int* value2 = (int*) p2;
	return (*value1 - *value2)*(-1);  	
}

int cmp_double(const void *p1, const void *p2) {
	double* value1 = (double*) p1;
	double* value2 = (double*) p2;
	return (*value1 - *value2 >= 0) ? 1 : -1;
}

int cmp_double_rev(const void *p1, const void *p2) {
	double* value1 = (double*) p1;
	double* value2 = (double*) p2;
	return (*value1 - *value2 >= 0) ? -1 : 1;
}

void insertion_sort(DynamicArray *base, int(*compar)(const void *, const void *)) {
	for (size_t i = 1; i < base->lenght; i++) {
		size_t j = i;
		while (j > 0 && compar(base->data[j], base->data[j-1]) < 0) {
			swap(base, j, j-1);
			j--;
		}
	}
}

void bubble_sort(DynamicArray *base, int(*compar)(const void *, const void *)) {
    for(size_t i = 0; i<base->lenght; i++) {
        for(size_t j = 0; j < base->lenght-i-1; j++) {
            if(compar(base->data[j], base->data[j+1]) > 0) {
                swap(base, j, j+1);
            }
        }
    }
}

void function_int(const void *a) {
    *(int*)a += 1;
}

void function_double(const void *a) {
    *(double*)a *= 2;
}

void some_map(DynamicArray* dynArr, void (*function)(const void*)) {
    for (size_t i = 0; i < dynArr->lenght; i++) {
        function(dynArr->data[i]);
    }
}

int condition_function_int(const void *a) {
    return (*(int*)a % 2 == 0)  ? 1 : 0; 
}

int condition_function_double(const void *a) {
	return (*(double*)a > 50) ? 1 : 0; 
}

void some_where_simple(DynamicArray* dynArr, int (*condition_function)(const void *), void (*function)(const void *)) {
    for (size_t i = 0; i < dynArr->lenght; i++) {
        if(condition_function(dynArr->data[i])) { 
            function(dynArr->data[i]);
        }
    }
}

void some_where(DynamicArray** dynArr, int (*condition_function)(const void *)) {

    for (size_t i = 0; i < (*dynArr)->lenght; i++) {
        //Функция фильтрует массив с помощью функции фильтра
        if(!condition_function((*dynArr)->data[i])) {
            free((*dynArr)->data[i]);
            for (size_t j = i; j < (*dynArr)->lenght-1; j++) {
                
                (*dynArr)->data[j] = (*dynArr)->data[j+1];
            }
            (*dynArr)->lenght--;
            i--;
            (*dynArr)->data = (void **) realloc((*dynArr)->data, (*dynArr)->lenght * sizeof(void *));
        }

    }
}

DynamicArray* some_where_hard(DynamicArray* dynArr, int (*condition_function)(const void *)) {
    DynamicArray* result = create_DynamicArray(dynArr->size_of_type, dynArr->lenght);
    size_t result_lenght = 0;
    size_t index = 0;
    for (size_t i = 0; i < dynArr->lenght; i++) {
        //Функция возвращает отфильтрованный массив с помощью функции-фильтра
        if(condition_function(dynArr->data[i])) {
            memcpy(result->data[index], dynArr->data[i], result->size_of_type);
            result_lenght++;
            index++;
        }
    }
    result->lenght = result_lenght;
    result->data = (void **) realloc(result->data, result->lenght * sizeof(void *));
    return result;
}

void some_concat(DynamicArray** dynArr1, DynamicArray* dynArr2) {
    if ((*dynArr1)->size_of_type != dynArr2->size_of_type) {
        return;
    }
    DynamicArray* result = create_DynamicArray((*dynArr1)->size_of_type, (*dynArr1)->lenght + dynArr2->lenght);
    
    //Копируем указатели из первого массива в новый.
    for (size_t i = 0; i < (*dynArr1)->lenght; i++) {
        memcpy(result->data[i], (*dynArr1)->data[i], result->size_of_type);
    }
    //Копируем указатели из второго массива в новый.
    for (size_t i = 0; i < dynArr2->lenght; i++) {
        memcpy(result->data[(*dynArr1)->lenght + i], dynArr2->data[i], result->size_of_type);
    }
    delete_DynamicArray((*dynArr1));
    *dynArr1 = result;
}

DynamicArray* some_concat_hard(DynamicArray* dynArr1, DynamicArray* dynArr2) {
    if (dynArr1->size_of_type != dynArr2->size_of_type) {
        return dynArr1;
    }
    DynamicArray* result = create_DynamicArray(dynArr1->size_of_type, dynArr1->lenght + dynArr2->lenght);
    
    //Копируем указатели из первого массива в новый.
    for (size_t i = 0; i < dynArr1->lenght; i++) {
        memcpy(result->data[i], dynArr1->data[i], result->size_of_type);
    }
    //Копируем указатели из второго массива в новый.
    for (size_t i = 0; i < dynArr2->lenght; i++) {
        memcpy(result->data[dynArr1->lenght + i], dynArr2->data[i], result->size_of_type);
    }
    return result;
}