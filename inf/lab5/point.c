#include <stdio.h>
#include <string.h>
#include "point.h"
#include <stdlib.h>
Point point_new(char* fio, char* number, int age) {
    Point p = {fio, number, age};
    return p;
}

void swap(Point *a, Point *b) {
	Point temp = *a;
	*a = *b;
	*b = temp;
}

void point_print(const Point *p) {
    printf("%s:", p->fio);
    printf("%s:", p->number);
    printf("%d", p->age);
}

int point_cmp_fio(const Point *p1, const Point *p2) {
    return strcmp(p1->fio, p2->fio);
}

int point_cmp_number(const Point *p1, const Point *p2) {
    return strcmp(p1->number, p2->number);
}

int point_cmp_age(const Point *p1, const Point *p2) {
	return p1->age - p2->age;	
}

int reverse_fio(const Point *p1, const Point *p2) {
	return strcmp(p1->fio, p2->fio) * (-1);
}

int reverse_number(const Point *p1, const Point *p2) {
	return strcmp(p1->number, p2->number) * (-1);
}

int reverse_age(const Point *p1, const Point *p2){
	return (p1->age - p2->age) * (-1); 
}

void point_array_print(const char *msg, const Point *arr, int len) {
    printf("%s", msg);
    for (int i = 0; i < len; ++i) {
       //printf("a[%d] = ", i);
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
		while (j > 0 && compar(&base[j], &base[j-1]) < 0) {
			swap(&base[j], &base[j - 1]); 
			j--;
		}
	}
}

void write_point(const char *path, Point *base, size_t len) { 
	FILE *fptr = fopen(path, "a"); 
	for (size_t i = 0; i < len; i++) { 
		Point p = base[i]; 
		fprintf(fptr, "%s:%s:%d\n",p.fio , p.number, p.age); 
	}
	
	fclose(fptr);
}

int read_fio(Point *p, FILE *fptr) { 
	char *fio = (char *)malloc(sizeof(char)); 
	fio[0] = '\0'; 
	int len = 0; 
	char buf[81] = {0};
	
	while (1) { 
		switch (fscanf(fptr, "%80[^:]", buf)) { 
			case -1:  
				free(fio); 
				return 0;
			case 0: 
				p->fio = fio; 
				return 1; 
			case 1: 
				len += strlen(buf); 
				fio = (char *)realloc(fio, sizeof(char) * (len + 1));
				fio[len] = '\0'; 
				strcat(fio, buf);
		}
	}
}
int read_number(Point *p, FILE *fptr) { 
 // TODO ADD format check 
 	p->number = (char*) malloc(sizeof(char)*8);
 	int check = fscanf(fptr, "%7[^:]", p->number);
	for(int i = 0; i<3;i++) {
		if((p->number)[i] < 65 || (p->number)[i] > 122 || ((p->number)[i] > 90 && (p->number)[i] < 97 )) {
			printf("Неправильный номер избирательного участка\n");
			return 0;
		}
	}
	if(p->number[3] != '-') {
		printf("Неправильный номер избирательного участка\n");
		return 0;
	}
	for(int i = 4; i<7;i++) {
		if(p->number[i] < 48 || p->number[i] > 57 ) {
			printf("Неправильный номер избирательного участка\n");
			return 0;
		}
	}
	switch (check) {
        case -1:
            return 0;
        case 0:
            return 0;
        case 1:
            p->number[7] = '\0';
            return 1;
    }
}
int read_age(Point *p, FILE *fptr) { 
	switch (fscanf(fptr, "%d", &(p->age))) { 
		case -1:
			return 0;
		case 0:
			return 0; 
		case 1: 
			return 1;
	}
}
int check_eof(FILE *fptr) { 
	if (fscanf(fptr, "%*c") == -1) { 
		return 1;
	}
	fseek(fptr, -1, SEEK_CUR); 
	return 0;
}
Point *read_point(const char *path, size_t *len_point) { 
	FILE *fptr = fopen(path, "r"); 
	Point *res = NULL; 
	int count = 0; 
	int capacity = 0;
	if (!fptr) {
		return NULL;
	}	
	while (!check_eof(fptr)) { 
		Point p; 
		int check = 1;
			
		if (check == read_fio(&p, fptr)) { 
			fscanf(fptr, "%*c");
		}
		if (check && (check = read_number(&p, fptr))) { 
			fscanf(fptr, "%*c");
		} 
		else {
			printf("Неправильный номер участка у избирателя номер %d\n",count+1);
		}
		if (check) { 
			check = read_age(&p, fptr);
		}
		
		if (check) { 
			if (count == capacity) { 
				capacity = (capacity == 0 ? 1 : capacity * 2); 
				res = (Point *)realloc(res, sizeof(Point) * capacity); 
				if (!res) {
		    		fclose(fptr); 
		    		return NULL;
				}
			}
			res[count] = p;
			count++;
		}
		else {
			free(p.fio);
			free(p.number);
		}
		fscanf(fptr, "%*[^\n]"); 
		fscanf(fptr, "%*c");
	}
	printf("Количество считанных избирателей: %d\n", count); 
	res = (Point *)realloc(res, sizeof(Point) * count); 
	fclose(fptr); 
	*len_point = count; 
	return res;
}
