#include <stdlib.h>
#include <stdio.h>
#include "point.h"

int main(int argc, char **argv) {
    Point arr[] = {
    	point_new("Bulgakov","CCC-999", 20), 
        point_new("Mikhailov", "AAA-777", 19),
        point_new("Khabarov","BBB-888",17),
        point_new("Bazhenov","CCC-999", 20), 
        point_new("Almakov", "ZZZ-555", 18),
        point_new("Makienko", "AAA-777", 19), 
        point_new("Grishanov","YYY-666", 18),
        point_new("Davydov", "XXX-444", 17)
    };
    point_array_print("Before sort:\n", arr, sizeof(arr)/sizeof(Point));
	//qsort(arr, sizeof(arr)/sizeof(Point), sizeof(Point), 
	//(int (*)(const void *, const void *)) point_cmp_x);
	//odd_even_sort(arr, sizeof(arr)/sizeof(Point), (int (*)(const Point *, const Point *)) (&point_cmp_x));
	insertion_sort(arr, sizeof(arr)/sizeof(Point), (int (*)(const Point *, const Point *)) (&point_cmp_x));
	point_array_print("After sort:\n", arr, sizeof(arr)/sizeof(Point));
    return 0;
}
