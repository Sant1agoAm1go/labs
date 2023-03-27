#ifndef DYNAR_H 
#define DYNAR_H 
#include <stddef.h>

typedef struct DynamicArray {
	size_t size_of_type; //Размер типа
	size_t lenght; //Количество элементов в динамическом массиве			
	void **data; //Указатель на массив указателей на АТД
} DynamicArray;

//Создание пустого динамического массива 
DynamicArray* create_DynamicArray(size_t size_of_type, size_t lenght);
 
//Удаление динамического массива
void delete_DynamicArray(DynamicArray* dynArr); 

//Заполняет динамический массив случайными числами
void fill_random_DynamicArray(DynamicArray* dynArr);
DynamicArray* create_random_DynamicArray(size_t size_of_type, size_t lenght);

//Заполняет массив определенными числами
void fill_definite_DynamicArray(DynamicArray* dynArr);
DynamicArray* create_definite_DynamicArray(size_t size_of_type, size_t lenght);

void DynamicArray_set(DynamicArray* dynArr, void* value, size_t index); 

void* DynamicArray_get(DynamicArray* dynArr, size_t index);

#endif
