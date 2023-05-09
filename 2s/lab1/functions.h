#ifndef FUNCTIONS_H 
#define FUNCTIONS_H 
#include "dynar.h"

//Функции для обработки коллекции

void check_int(int *input);

int cmp_int(const void *p1, const void *p2);

int cmp_int_rev(const void *p1, const void *p2);

int cmp_double(const void *p1, const void *p2);

int cmp_double_rev(const void *p1, const void *p2);

void function_int(const void *a); 

void function_double(const void *a);

void* reducer_int(int* a, int* b, void* result);

void* reducer_double(double* a, double* b, void* result);

int condition_function_int(const void *a);

int condition_function_double(const void *a);

void some_map(DynamicArray* dynArr, void (*function) (const void*)); 

void some_where_simple(DynamicArray* dynArr, int (*condition_function)(const void *), void (*function)(const void *));

void some_where(DynamicArray** dynArr, int (*conditionFunction) (const void*));

DynamicArray* some_where_hard(DynamicArray* dynArr, int (*condition_function)(const void *));

void* reduce(void* (*func)(void*,void*, void*), void* start, DynamicArray* dynArr);

void some_concat(DynamicArray** dynArr1, DynamicArray* dynArr2);

DynamicArray* some_concat_hard(DynamicArray* dynArr1, DynamicArray* dynArr2);

void insertion_sort(DynamicArray *base, int(*compar)(const void *, const void *));

void bubble_sort(DynamicArray *base, int(*compar)(const void *, const void *));

//Функция printf для разных типов элементов
void some_printf(DynamicArray* dynArr);

#endif