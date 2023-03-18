#include <stdio.h>
#include <stdlib.h>
#include "zag.h"

void array_insert(int *len1, double *data1) {
    printf("Введите пару индекс-значение: ");
    int n = 0;
    double z = 0;
    scanf("%d %lf", &n, &z);
    if (n<*len1) {
    	if(data1[n]>=0 || data1[n]<0) {
        	*len1 = *len1 + 1;
       		 data1 = (double*) realloc(data1,*len1 * sizeof(double));
       		 for (int x = *len1-1; x>n-1; x--) {
       		 	data1[x+1] = data1[x];
       		 }
        }
        data1[n] = z;
    }
    if (n >=*len1) {
    	data1 = (double*) realloc(data1, (n+1) * sizeof(int));
    	for (int v = *len1; v<n+1; v++) {
    		data1[v] = 0;
    	}
    	*len1 = n+1;
    	data1[n] = z;
	}
}
double *array_input1(int *len1, double *s) {
    printf("Elem: ");
    scanf("%d", len1);
    double *data1 = (double *) malloc(*len1 * sizeof(double));
    if (!data1) {
        printf("Error");
        return NULL;
        }
        for (int i = 0; i < *len1; i++) {
            printf("data[%d] = ", i);
            scanf("%lf", &data1[i]);
            *s = *s + data1[i];
        }
    *s = *s/(*len1);
    printf("Среднее значение: %lf\n", *s);
    return data1;

}
double *array_input2(int *len1, double * s, double *data1) {
    double *data2 = (double *) malloc(*len1 * sizeof(double));
    if (!data2) {
        printf("Error");
        return NULL;
        }
        for (int j = 0; j < *len1; j++) {
            data2[j] = data1[j]-(*s);
        }
    return data2;
}
double *array_remove2(int *len2, int *len1, double *s, double *data1 ){
    *len2 = *len1;
    for (int h = 0; h < *len2; h++) {
        if (data1[h]>(*s)) {
            for(int m = h; m < *len2-1; m++ ) {
                data1[m] = data1[m+1];
            }
            (*len2)--;
            h--;
        }
    }
    return data1;
}
void array_print(int *len1, double *data1) {
        for (int k = 0; k < *len1; k++) {
            printf("data[%d] = %lf \n", k, data1[k]);
        }
}
