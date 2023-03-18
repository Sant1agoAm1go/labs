#include <stdio.h>
#include <string.h>
#include "point.h"

Point point_new(char* x, char* y, int z) {
    Point p = {x, y, z};
    return p;
}

void swap(Point *a, Point *b) {
	Point temp = *a;
	*a = *b;
	*b = temp;
}

void point_print(const Point *p) {
    printf("{%s, %s, %d}", p->x, p->y, p->z);
}

int point_cmp_x(const Point *p1, const Point *p2) {
    return strcmp(p1->x, p2->x);
}

int point_cmp_y(const Point *p1, const Point *p2) {
    return strcmp(p1->y, p2->y);
}

int point_cmp_z(const Point *p1, const Point *p2) {
	return p1->z - p2->z;	
}

int reverse_x(const Point *p1, const Point *p2) {
	return strcmp(p1->x, p2->x) * (-1);
}

int reverse_y(const Point *p1, const Point *p2) {
	return strcmp(p1->y, p2->y) * (-1);
}

int reverse_z(const Point *p1, const Point *p2){
	return (p1->z - p2->z) * (-1); 
}

void point_array_print(const char *msg, const Point *arr, int len) {
    printf("%s", msg);
    for (int i = 0; i < len; ++i) {
        printf("a[%d] = ", i);
        point_print(arr + i);
        printf("\n");
    }
}

void odd_even_sort(Point *base, size_t len, int(*compar)(const Point *, const Point *)) {
	for(size_t i = 0; i < len; i++) {
		// (i % 2) ? 0 : 1 возвращает 1, если i четное, 0, если i не четноеodd
		for(size_t j = (i % 2) ? 0 : 1; j + 1 < len; j+=2) {
			if(compar(&base[j], &base[j + 1]) > 0) {
				swap(&base[j], &base[j + 1]);
			}
				
		}
	}
}
void insertion_sort(Point *base, size_t len, int(*compar)(const Point *, const Point *)) {
	for (size_t i = 1; i < len; i++) {
		size_t j = i;
		while (j > 0 && compar(&base[j], &base[j - 1]) < 0) {
			swap(&base[j], &base[j - 1]); 
			j--;
		}
	}
}
