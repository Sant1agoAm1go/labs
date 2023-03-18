#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include <stdlib.h>

int main() {
	char input[81] = {0};
	char output[81] = {0};
	printf("Введите имя входного и выходного файла через пробел: ");  
	scanf("%s %s", input, output);
	int alg = 0, compar = 0; 
	void *comparator;
	size_t len_point = 0;
	printf("Введите сортировку и компаратор через пробел\nСортировки:\n1 - qsort;\n2 - odd-even_sort;\n3 - insertion_sort\nКомпараторы:\n1 - point_cmp_fio;\n2 - point_cmp_number;\n3 - point_cmp_age;\n4 - reverse_fio;\n5 - reverse_number;\n6 - reverse_age\n");
	printf("> ");
	scanf("%d %d", &alg,  &compar);
	Point *arr = read_point(input, &len_point);
	point_array_print("Before sort:\n", arr, len_point); 
	switch(compar) { // 1 - point_cmp_fio; 2 - point_cmp_number; 3 - point_cmp_age; 4 - reverse_fio; 5 - reverse_number; 6 - reverse_age
			case 1:
				comparator = &point_cmp_fio;
				break;
			case 2: 
				comparator = &point_cmp_number;
				break;
			case 3:
				comparator = &point_cmp_age;
				break;
			case 4: 
				comparator = &reverse_fio;
				break;
			case 5:
				comparator = &reverse_number;
				break;
			case 6: 
				comparator = &reverse_age;
				break;
	}  
			 
	switch(alg) { // 1 - quick; 2 - odd_even; 3 - insert
		case 1:
			qsort(arr, len_point, sizeof(Point), (int (*)(const void *, const void *)) comparator);
			break;
		case 2: 
			odd_even_sort(arr, len_point, (int (*)(const Point *, const Point *)) comparator);
			break;
		case 3:
			insertion_sort(arr, len_point, (int (*)(const Point *, const Point *)) comparator);
			break; 			
			 
	}
	point_array_print("After sort:\n", arr, len_point); 
	write_point(output, arr, len_point);
    /*Point arr[] = {
    	point_new("Bulgakov","CCC-999", 20), 
        point_new("Mikhailov", "AAA-777", 19),
        point_new("Khabarov","BBB-888",17),
        point_new("Bazhenov","CCC-999", 20), 
        point_new("Almakov", "ZZZ-555", 22),
        point_new("Kuzmin", "ABC-123", 18),
        point_new("Makienko", "AAA-777", 21), 
        point_new("Grishanov","YYY-666", 18),
        point_new("Davydov", "XXX-444", 17)
    };*/
    
    //point_array_print("Before sort:\n", arr, sizeof(arr)/sizeof(Point));
	//qsort(arr, sizeof(arr)/sizeof(Point), sizeof(Point), (int (*)(const void *, const void *)) point_cmp_x);
	//odd_even_sort(arr, sizeof(arr)/sizeof(Point), (int (*)(const Point *, const Point *)) (&point_cmp_x));
	//insertion_sort(arr, sizeof(arr)/sizeof(Point), (int (*)(const Point *, const Point *)) (&point_cmp_x));
	//point_array_print("After sort:\n", arr, sizeof(arr)/sizeof(Point));
	//Point *arr = read_point("input.txt", &len_point); 
	//insertion_sort(arr, len_point, (int (*)(const Point *, const Point *)) point_cmp_age);
	//point_array_print("After sort:\n", arr, len_point);
	//write_point("output.txt", arr, len_point);
	for(size_t i = 0; i < len_point; i++ ) {
		free(arr[i].fio);
		free(arr[i].number);
	}
	free(arr);
    return 0;
}
