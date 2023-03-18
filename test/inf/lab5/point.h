#ifndef POINT_H
#define POINT_H
#include <stddef.h>
//#include <stdio.h>
typedef struct Point {
    char *fio, *number;
    int age;
} Point;

Point point_new(char *fio, char* number, int age);

void swap(Point *a, Point *b);

void point_print(const Point *p);

int point_cmp_fio(const Point *p1, const Point *p2);

int point_cmp_number(const Point *p1, const Point *p2);

int point_cmp_age(const Point *p1, const Point *p2);

int reverse_fio(const Point *p1, const Point *p2);

int reverse_number(const Point *p1, const Point *p2);

int reverse_age(const Point *p1, const Point *p2);

void odd_even_sort(Point *base, size_t len, int(*compar)(const Point *, const Point *));

void insertion_sort(Point *base, size_t len, int(*compar)(const Point *, const Point *));

void point_array_print(const char *msg, const Point *arr, int len);

void write_point(const char *path, Point *base, size_t len);

Point *read_point(const char *path, size_t *len_point);

#endif
