#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void process(int **arr, int *len) {
	/*for(int i = 0; i<*len; i++) {
		while((*arr)[i]/10>0 && (*arr)[i] != 0) {
			(*len)++;
			*arr = (int *) realloc(*arr, *len*sizeof(int));
			for(int j = *len-1; j > i; j--) {
				(*arr)[j] = (*arr)[j-1]; 
			}
			(*arr)[i+1] = (*arr)[i]%10;
			(*arr)[i]/=10;
		}
	} 
	for(int i = 0; i < *len; i++) {
		if((*arr)[i] < 0) {
			for(int j = i; j <*len-1; j++) {
				(*arr)[j] = (*arr)[j+1];
			}	
			(*len)--; 
			i--;
			*arr = (int *) realloc(*arr, *len*sizeof(int));
		} 
		else if((*arr)[i] > 0) {
			(*len)++;
			*arr = (int *) realloc(*arr, *len*sizeof(int));
			for(int j = *len-1; j > i; j--){
				(*arr)[j] = (*arr)[j-1];
			}
			i++;		
			
		}
	}*/ 
	int l = *len;
	int arr2[l]; 
	for(int i = 0; i < l; i++) {
		arr2[i] = (*arr)[i]; 
	}
	int s = 0;
	for(int i = 0; i < *len; i++) {
		for( int j = 0; j < l; j++) {
		
			if((*arr)[i] >= arr2[j]) {
				s+=arr2[j];
			}	
        }	
		(*len)++; 
		*arr = (int *) realloc(*arr, *len*sizeof(int));
		for(int k = *len-1; k > i; k--) {
			(*arr)[k] = (*arr)[k-1]; 
		}
		(*arr)[i+1] = s;
		i++; 
		s = 0;
		
	}
	
}

int main() {
	srand(time(NULL));
	int len = 4;
	int *arr = (int*) malloc(len * sizeof(int)); 
	for(int i = 0; i < len; i++) {
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}
	/*for (int i = len/2; i < len; i++) {
		arr[i] = -(rand() % 1000);
		printf("%d ", arr[i]);
	}*/
	printf("\n");
	process(&arr, &len);
	for(int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("%d ", -125/10); 
	printf("%d ", -125%10);
	return 0; 
}
