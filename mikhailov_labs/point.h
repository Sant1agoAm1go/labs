#ifndef POINT_H
#define POINT_H
#include <stddef.h>

typedef struct Point {
    char *x,*y;
    int z;
} Point;

Point point_new(char *x, char* y, int z);

void point_print(const Point *p);

int point_cmp_x(const Point *p1, const Point *p2);

int point_cmp_y(const Point *p1, const Point *p2);

int point_cmp_z(const Point *p1, const Point *p2);

int reverse_x(const Point *p1, const Point *p2);

int reverse_y(const Point *p1, const Point *p2);

int reverse_z(const Point *p1, const Point *p2);

void odd_even_sort(Point *base, size_t len, int(*compar)(const Point *, const Point *));

void insertion_sort(Point *base, size_t len, int(*compar)(const Point *, const Point *));

void point_array_print(const char *msg, const Point *arr, int len);
#endif
