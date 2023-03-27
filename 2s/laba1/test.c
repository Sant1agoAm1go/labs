#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "dynar.h" 
#include "functions.h"
void testing() {
    srand(time(NULL));
	void* comparator = NULL;
	void* function = NULL;
	void* condition_function = NULL;
	DynamicArray *dynArr1 = NULL;
	DynamicArray *dynArr2 = NULL;
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
			comparator = &cmp_int;
			function = &function_int;
			condition_function = &condition_function_int;
			dynArr1 = create_DynamicArray(sizeof(int),lenght1);
			dynArr2 = create_DynamicArray(sizeof(int),lenght2);
			break;
		case 2: 
			comparator = &cmp_double;
			function = &function_double;
			condition_function = &condition_function_double;
			dynArr1 = create_DynamicArray(sizeof(double),lenght1);
			dynArr2 = create_DynamicArray(sizeof(double),lenght2);
			break;
	}
	fill_definite_DynamicArray(dynArr1);
	fill_definite_DynamicArray(dynArr2);
	printf("first array:\n");
    some_printf(dynArr1);	
	printf("\n");
	//insertion_sort(dynArr1, comparator);
	bubble_sort(dynArr1, comparator);
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
	some_map(dynArr1, function);
	some_printf(dynArr1);
	printf("\n");
	printf("where function:\n");
	some_where(&dynArr1, condition_function);
	some_printf(dynArr1);
	//DynamicArray *where_arr = some_where_hard(dynArr1, condition_function);
	//some_printf(where_arr);
	printf("\n");
	delete_DynamicArray(dynArr1);
	delete_DynamicArray(dynArr2);
	//delete_DynamicArray(concat_arr);
	//delete_DynamicArray(where_arr);
}