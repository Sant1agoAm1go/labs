#include <iostream> 
#include <stdio.h>
#include "Pointers.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "Array.h"
#include <time.h>
#include <chrono>
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

void bubble_sort_raw(int *base, int len, int(*compar)(const void *, const void *)) {
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

void insertion_sort_raw(int* base, int len, int(*compar)(const void *, const void *)) {
	for (size_t i = 1; i < len; i++) {
		size_t j = i;
		while (j > 0 && compar(&base[j], &base[j-1]) < 0) {
			swap(base, j, j-1);
			j--;
		}
	}
}

void insertion_sort_smart(ShrdPtr<int> base, int len, int(*compar)(const void *, const void *)) {
	for (size_t i = 1; i < len; i++) {
		size_t j = i;
		while (j > 0 && compar(&base[j], &base[j-1]) < 0) {
			swap(base, j, j-1);
			j--;
		}
	}
}

void heapify_raw(int* arr, int n, int i)
{
    int largest = i;   
    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr, i, largest);
        heapify_raw(arr, n, largest);
    }
}


void heap_sort_raw(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_raw(arr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(arr, 0, i);
        heapify_raw(arr, i, 0);
    }
}

void heapify_smart(ShrdPtr<int> arr, int n, int i)
{
    int largest = i;   
    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr, i, largest);
        heapify_smart(arr, n, largest);
    }
}


void heap_sort_smart(ShrdPtr<int> arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_smart(arr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(arr, 0, i);
        heapify_smart(arr, i, 0);
    }
}

int main() {
    srand(time(nullptr));
    int len = 100000;
    int count = 1000;
    double avg_raw = 0;
    double avg_smart = 0;
    for(int i = 0; i < count; i++) {
        int* data = new int[len];
        for(int i = 0; i < len; i++) {
            data[i] = rand() % 100;
        }
        int* data2 = new int[len];
        ShrdPtr<int> ptr(data2);
        for(int i = 0; i < len; i++) {
            ptr[i] = data[i];
        }

        clock_t raw_start = clock();
        heap_sort_raw(data, len);
        double raw_res = (double) (clock() - raw_start) / CLOCKS_PER_SEC; 
        avg_raw += raw_res;
        
        clock_t smart_start = clock();
        heap_sort_smart(ptr, len);
        double smart_res = (double) (clock() - smart_start) / CLOCKS_PER_SEC; 
        avg_smart += smart_res;
        delete data;
    }
    avg_raw/=count;
    avg_smart/=count;
    printf("raw ptr: %.8lf\nsmart ptr: %.8lf\n", avg_raw, avg_smart);
    return 0;
}