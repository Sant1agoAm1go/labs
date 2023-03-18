#include <stdlib.h> 
#include <stdio.h>
void process(int **array, int *size){ 
for(int i = 0; i<*size; i++){ 
if ((*array)[i]<0) { for(int k = i; k<*size-1;k++){
                
            }
            i--; 
            (*size)--; 
            *array = (int *) realloc (*array, *size*sizeof(int));
            
        }
        else if((*array)[i]>0) { 
        (*size)++; 
        *array = (int *) realloc(*array, *size*sizeof(int)); 
        for (int k = *size-1; k > i-1; k--){ 
        (*array)[k+1] = (*array)[k+1];
            }
            (*array)[i+1] = (*array)[i]; i--;
        }
    }
}
int main () { int *arr = (int *) calloc(8, sizeof(int)); arr[0] = 344; arr[1] = 6530; arr[2] = -8206; arr[3] = 1711; arr[4] = 0; arr[5] = 3508; arr[6] = -4388; arr[7] = 597; int size = 8; 
    process(&arr,&size); 
    for(int i = 0; i<8; i++){
    	printf("%d", arr[i]);
    }
}
