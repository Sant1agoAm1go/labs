#ifndef ZAG3_H 
#define ZAG3_H 

int check_int(int *input);

int check_double(double *input);

void mid_value(double *s,int *len_true, double **data);
 
int array_insert(int *len, int *len_true, double **data, double *s); 

int array_remove2( int *len, int *len_true, double **data, double *s);

//int array_input(int *len, double *s,double *data);
 
int array_input1(int *len, int *len_true, double *s, double **data);

int array_add(int *len, double **data);
 
double *array_input2(int *len, double * s, double *data); 
 
double *array_remove( int *len, int *len_true, double **data, double *s); 
 
void array_print(int len, int len_true, double *data, double s);
 
#endif
