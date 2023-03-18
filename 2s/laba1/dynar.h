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

//Функция printf для разных типов элементов
void some_printf(DynamicArray* dynArr);
 
//Удаление динамического массива
void delete_DynamicArray(DynamicArray* dynArr); 

//Заполняет динамический массив случайными числами
void fill_DynamicArray(DynamicArray* dynArr);
#endif
