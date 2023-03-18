#include <stdio.h>
#include <stdlib.h>
#include "zag3.h"

//%*c  ban
//%*[^\n]

int check_int(int *input){
	int check = 0;
	while(check != 1) {
		check = scanf("%d", input);
		if (check == EOF) {
			printf("\nПринудительное завершение программы\n");
			return 1;
		}
		if (check == 1) {
			break;
		}
		printf("Введены некорректные данные! Введите число!\n");
		printf("Список функций:\n");
        printf("1 - инициализация массива\n");
        printf("2 - вывод текущего состояния массива\n");
        printf("3 - вставка элемента по индексу\n");
        printf("4 - удаление элемента по индексу\n" );
        printf("5 - индивидуальное задание\n");
        printf("6 - добавить количество элементов\n");
        printf("0 - выйти из программы\n");
		scanf("%*[^\n]"); 
	}
	return 0;
}

int check_double(double *input){
    int check = 0;
    while(check != 1) {
        check = scanf("%lf", input);
        if (check == EOF) {
			printf("\nПринудительное завершение программы\n");
            return 1;
        }
        if (check == 1) {
            break;
        }
        printf("Введены некорректные данные! Введите число!\n");
        scanf("%*[^\n]");
    }
    return 0;
}

int array_add(int *len, double **data){
	printf("len = %d\n",*len);
	int add = 0;
	printf("Количество элементов: ");
	int error = check_int(&add);
	if (error == 1){
		return 1;
	}
	*data = (double*) realloc(*data, (add+(*len))*sizeof(double));
	(*len)+=add;
	return 0;
}

void mid_value(double *s, int *len_true, double **data){
	*s = 0;
	for(int i = 0; i < *len_true; i++) {
		(*s) += (*data)[i];
	}
	*s = *s / (*len_true);
}

int array_input1(int *len, int *len_true, double *s,  double **data) {
    *s = 0;
    printf("Elem: ");
    int error1 = check_int(len);
    if(error1 == 1){
        return 1;
    }
    *data = (double*) calloc(*len, sizeof(double));
    for(int i = 0; i < *len; i++) {
        printf("data[%d] = ", i);
        int error2 = check_double(&((*data)[i]));
        if(error2 == 1) {
            return 1;
        }
    }
    *len_true = *len;
    mid_value(s,len_true,data);
    printf("Среднее значение = %lf\n",*s);
    return 0;
}
 
int array_insert(int *len, int *len_true, double **data, double *s ) {
    printf("Введите пару индекс-значение: ");
    int n = 0;
    double z = 0;
    int error1 = check_int(&n);
    int error2 = check_double(&z);
    if(error1 == 1 || error2 == 1) {
        return 1;
    }
    
    if (n < *len_true && n >= 0) {
    	(*data)[n] = z;
    }
    
	else if (*len > *len_true && n >= *len_true && n >= 0) {
            (*len_true)++;
            (*data)[(*len_true)-1] = z;
        
    }
    else {
    	if(*len_true == *len && n >= 0 ){
        	printf("Ошибка! Не хватает памяти! Добавьте количество элементов!\n");
        	//array_add(len,data);
        	//(*len_true)++;
        	//(*data)[(*len_true)-1] = z;
        }
        if (n < 0){
        	printf("Такого индекса не существует! Введите неотрицательный индекс!\n");
        }
    }
    
    mid_value(s,len_true, data);
    return 0;
}

/*int array_insert(int *len, int *len_true, double **data, double *s ) {
    printf("Введите пару индекс-значение: ");
    printf("len = %d\n",*len);
    int n = 0;
    double z = 0;
    int error1 = check_int(&n);
    int error2 = check_double(&z);
    if(error1 == 1 || error2 == 1) {
    	return 1;
    }
    if (n < *len) {
    	if(n < *len_true){	
    		(*data)[n] = z;
   		} 
    }
    if (*len_true == *len || n>=*len_true) {
    	printf("Ошибка! Не хватает памяти! Добавьте количество элементов!\n");
    	array_add(len,data);
    	(*len_true)++;
    	(*data)[(*len_true)-1] = z;
    }
    mid_value(s,len_true, data);
    return 0;
}*/
/*int array_input(int *len1, double *s, double **data) {
   // printf("Elem: ");
    //int error1 = check_int(len1);
   // if (error1 == 1) {
    //	return 1;
   // }
   // *data = (double *) malloc(*len1 * sizeof(double));
   // for (int i = 0; i < *len1; i++) {
       // printf("data[%d] = ", i);
       // int error2= check_double(&((*data)[i]));
       // if (error2 == 1){
        //	return 1;
       // }
        *s += (*data)[i];
    //}
  // 	*s = *s/(*len1);

   // printf("Среднее значение: %lf\n", *s);
//	return 0;
//56}*/

double *array_input2(int *len, double *s, double *data) {
    double *data2 = (double *) malloc(*len * sizeof(double));
        for (int j = 0; j < *len; j++) {
            data2[j] = data[j]-(*s);
        }
    return data2;
}

double *array_remove(int *len, int *len_true, double **data, double *s) {
	for (int h = 0; h < (*len_true); h++) {
		if ((*data)[h]>*s){
			for(int m = h; m  < (*len_true)-1; m++ ) {
                (*data)[m] = (*data)[m+1];
   			 }	 
   			(*len)--;
   			(*len_true)--;
   			h--;
   			*data = (double *) realloc (*data, (*len)* sizeof(double));
       } 
   }
   mid_value(s,len_true, data);
   return *data;
}

int array_remove2(int *len, int *len_true, double **data, double *s) {
	int a = 0;
	printf("Введите индекс удаляемого элемента: ");
	int error = check_int(&a);
	if (error == 1){
		return 1;
	}
	if(a < 0 || a >= *len_true) {
		printf("Такого индекса не существует! Введите неотрицательный индекс!\n");
	}
	else {
    	//for (int h = 0; h < *len3; h++) {
    	for(int m = a; m < (*len_true)-1; m++ ) {
      		(*data)[m] = (*data)[m+1];
    	}
    	(*len)--;
    	(*len_true)--;
    	*data = (double *) realloc(*data, (*len) * sizeof(double));
    	mid_value(s,len_true,data);
    }
    return 0;
}

void array_print(int len, int len_true, double *data, double s) {
	for (int k = 0; k < len_true; k++) {
		printf("data[%d] = %lf \n", k, data[k]);
	}
	printf("len = %d\n", len);
	printf("len_true = %d\n", len_true);
	printf("Среднее значение = %lf\n", s); 
}
