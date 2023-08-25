#include <iostream> 
#include "Pointers.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "Array.h"
#include <time.h>
void swap(int* data, int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void swap(ShrdPtr<int> data, int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

int cmp_int(const void *p1, const void *p2) {
	int* value1 = (int*) p1;
	int* value2 = (int*) p2;
	return *value1 - *value2;  	
}

void bubble_sort(int *base, int len, int(*compar)(const void *, const void *)) {
    for(size_t i = 0; i<len; i++) {
        for(size_t j = 0; j < len-i-1; j++) {
            if(compar(&base[j], &base[j+1]) > 0) {
                swap(base, j, j+1);
            }
        }
    }
}

void bubble_sort_smart(ShrdPtr<int> base, int len, int(*compar)(const void *, const void *)) {
    for(size_t i = 0; i<len; i++) {
        for(size_t j = 0; j < len-i-1; j++) {
            if(compar(&base[j], &base[j+1]) > 0) {
                swap(base, j, j+1);
            }
        }
    }
}

int main() {
    srand(time(nullptr));
    int len = 1000000;
    int* data = new int[len];
    
    for(int i = 0; i < len; i++) {
        data[i] = rand() % 100;
    }
    clock_t start = 0;
    ShrdPtr<int> ptr2(data);
    bubble_sort_smart(ptr2, len, cmp_int);
    double res = (double) (clock() - start) / CLOCKS_PER_SEC;
    std::cout << res << std::endl;
    return 0;
}