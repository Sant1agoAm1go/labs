#include <stdlib.h>
#include "point.h"
#include <time.h>
#include <stdio.h>

char random_digit() {
	return '0' + (rand() % 10);
	
}
char random_upper() {
	return 'A' + (rand() % ('Z' - 'A' + 1)); 
}
char random_lower() {
	return 'a' + (rand() % ('z' - 'a' + 1));
}

char random_letter() {
	char letter = 'A' + (rand() % ('z' - 'A' + 1));
	if(letter > 90 && letter < 97) {
		random_letter();
	}
	else {
		return letter;
	}
}

Point *generation(int len) {  
	Point *res = (Point *)malloc(sizeof(Point) * len);
	
	for (int i = 0; i < len; i++) { 
		res[i].fio = (char *)malloc(sizeof(char) * 31);
		res[i].fio[0] = random_upper(); 
		for (int j = 1; j < 10; j++) { 
			res[i].fio[j] = random_lower();
		}
		res[i].fio[10] = ' ';
		res[i].fio[11] = random_upper();
		for (int j = 12; j < 20; j++) {
			res[i].fio[j] = random_lower();	
		}
		res[i].fio[20] = ' ';
		res[i].fio[21] = random_upper();
		for (int j = 22; j < 30; j++) {
			res[i].fio[j] = random_lower(); 
		}
		res[i].fio[30] = '\0'; 		 
		
		res[i].number = (char*) malloc(sizeof(char)*8);
		res[i].number[0] = random_letter();
		res[i].number[1] = random_letter();
		res[i].number[2] = random_letter();
		res[i].number[3] = '-'; 
		res[i].number[4] = random_digit();
		res[i].number[5] = random_digit(); 
		res[i].number[6] = random_digit();
		res[i].number[7] = '\0';
		res[i].age = 18 + rand() % 83;
	}
	return res;
}
int main(int argc, char **argv) {
	srand(time(NULL));
    int alg = 0, compar = 0, elem_count = 0, arr_count = 0;
    void *comparator;
    printf("Введите количество элементов в генерируемых массивах и количество генерируемых массивов через пробел: ");
    scanf("%d %d", &elem_count,  &arr_count);
    printf("Введите сортировку и компаратор через пробел\nСортировки:\n1 - qsort;\n2 - odd_even sort;\n3 - insertion_sort\nКомпараторы:\n1 - point_cmp_fio;\n2 - point_cmp_number;\n3 - point_cmp_age;\n4 - reverse_fio;\n5 - reverse_number;\n6 - reverse_age\n");
    printf("> ");
    scanf("%d %d", &alg,  &compar);
    //Point *arr = read_point(input, &len_point);
    //point_array_print("Before sort:\n", arr, len_point);
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
    Point **points = (Point **) malloc(sizeof(Point *) * arr_count);
    for (int i = 0; i < arr_count; i++) {
    	points[i] = generation(elem_count);
    	point_array_print("Before sort:\n", points[i], elem_count);	
    }
    double end =  0, avg = 0;
    clock_t start = 0;
    for (int i = 0; i < arr_count; i++) { 
	   switch(alg) { // 1 - quick; 2 - odd_even; 3 - insert
    		case 1:
    		    start = clock();
        		qsort(points[i], elem_count, sizeof(Point), (int (*)(const void *, const void *)) comparator);
        		end =  (double)(clock() - start) / CLOCKS_PER_SEC;
        		avg+=end;
        		point_array_print("After sort:\n", points[i], elem_count); 
            	break;
        	case 2:
				start = clock();        	
            	odd_even_sort(points[i], elem_count, (int (*)(const Point *, const Point *)) comparator);
				end =  (double)(clock() - start) / CLOCKS_PER_SEC;
            	avg+=end;
                point_array_print("After sort:\n", points[i], elem_count);
            	break;
        	case 3:
        		start = clock();
            	insertion_sort(points[i], elem_count, (int (*)(const Point *, const Point *)) comparator);
            	end =  (double)(clock() - start) / CLOCKS_PER_SEC;
            	avg+=end;
            	point_array_print("After sort:\n", points[i], elem_count);
            	break;

    	}
    }

	for(int i = 0; i < arr_count; i++) {
		for(int j = 0; j< elem_count; j++) {
			free(points[i][j].fio);
			free(points[i][j].number);
		}
		free(points[i]);
	}
	free(points);
	
    
    avg/=arr_count;
    printf("На сортировку %d элементов ушло %lf секунд\n", elem_count, avg);
    //point_array_print("After sort:\n", arr, len_point);
	//write_point(output, arr, len_point);
    return 0;
}
