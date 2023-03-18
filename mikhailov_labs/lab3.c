#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "zag.h"
int main () {
	double s = 0;
    int len1 = 0, len2 = 0, flag = 1,input = 0;
    double *data1 = array_input1(&len2,&s);
    clock_t start = clock();
	while(flag) {
		printf("Список функций:\n");
		printf("1 - вставка элемента массива по индексу\n");
		printf("2 - вывод текущего состояния массива\n");
		printf("3 - индивидуальное задание\n");
		scanf("%d",&input);
		
		if (input == 2) {
			array_print(&len1,data1);
		}
		
		if (input == 1) {
			array_insert(&len1,data1);
		}
		
		if (input == 3 ) {
   		    double *data2 = array_input2(&len1,&s,data1);
    		printf("\nfirst mas:\n");
    		array_print(&len1, data1); 
    		printf("\nsecond mas:\n");
    		array_print(&len1,data2);  
    		data1 = array_remove2(&len2,&len1,&s,data1);
   			printf("\nfirst mas without wrong numbers:\n"); 
    		array_print(&len2,data1);
    		double end = ((double)(clock()- start)) / CLOCKS_PER_SEC;
    		printf("\nВремя выполнения функций: %lf секунд\n",end);
    		free(data1);
    		free(data2);
		}
		if(input == 0) {
			flag = 0;
		}
		
	}
	return 0;
}
