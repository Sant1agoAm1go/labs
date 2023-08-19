#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "dynar.h" 
#include "functions.h"
#include <string.h>
void testing() {
    srand(time(NULL));
	void* start = NULL;
	void* comparator = NULL;
	void* function = NULL;
	void* condition_function = NULL;
	void* reducer = NULL;
	DynamicArray *dynArr1 = NULL;
	DynamicArray *dynArr2 = NULL;
	int value_int = 4;
	double value_double = 4.0;
	int lenght1 = 0, lenght2 = 0, n = 0;
	printf("Enter the type of elements: 1 - integer, 2 - real\n");
    check_int(&n);
    while(n != 1 && n != 2) {
        printf("This number doesn't exist! Enter correct number!\n");
        check_int(&n);
    }
	printf("Enter the lenght of first array: ");
    check_int(&lenght1);
	//scanf("%d", &lenght1);
    printf("Enter the lenght of second array: ");
    check_int(&lenght2);
	//scanf("%d", &lenght2);
	switch(n) {
		case 1: 
			comparator = (void*) &cmp_int;
			function = (void*) &function_int;
			condition_function = (void*) &condition_function_int;
			reducer = (void*) &reducer_int;
			start = malloc(sizeof(int));
			memcpy(start, &value_int, sizeof(int));
			dynArr1 = create_DynamicArray(sizeof(int),lenght1);
			dynArr2 = create_DynamicArray(sizeof(int),lenght2);
			break;
		case 2: 
			comparator = (void*) &cmp_double;
			function = (void*) &function_double;
			condition_function = (void*) &condition_function_double;
			reducer = (void*) &reducer_double;
			start = malloc(sizeof(double));
			memcpy(start, &value_double, sizeof(double));
			dynArr1 = create_DynamicArray(sizeof(double),lenght1);
			dynArr2 = create_DynamicArray(sizeof(double),lenght2);
			break;
	}

	fill_random_DynamicArray(dynArr1);
	fill_random_DynamicArray(dynArr2);
	printf("first array:\n");
	some_printf(dynArr1);	
	printf("\n");

	//insertion_sort(dynArr1, comparator);
	bubble_sort(dynArr1, (int (*)(const void *, const void *)) comparator);
	printf("first array sorted:\n");
	some_printf(dynArr1);
	printf("\n");

    printf("second array:\n");
	some_printf(dynArr2);
	printf("\n");

	printf("concatenation of first array and second array:\n");
	some_concat(&dynArr1, dynArr2);
	some_printf(dynArr1);
	//DynamicArray *concat_arr = some_concat_hard(dynArr1, dynArr2);
	//some_printf(concat_arr);
	printf("\n");

	printf("map function:\n");
	some_map(dynArr1, (void (*)(const void*)) function);
	some_printf(dynArr1);
	printf("\n");

	printf("where function:\n");
	some_where(&dynArr1, (int (*)(const void*)) condition_function);
	some_printf(dynArr1);
	//DynamicArray *where_arr = some_where_hard(dynArr1, condition_function);
	//some_printf(where_arr);
	printf("\n");

	printf("Enter numbers for reduce_arr:\n");
	DynamicArray* reduce_arr = create_definite_DynamicArray(sizeof(int), 3);
	printf("\n");
	printf("reduce function:\n");
	int* result = (int*) reduce((void* (*)(void*,void*, void*))reducer, start, reduce_arr);
	printf("%d", *result);
	printf("\n");

	delete_DynamicArray(dynArr1);
	delete_DynamicArray(dynArr2);
	//delete_DynamicArray(concat_arr);
	//delete_DynamicArray(where_arr);
}