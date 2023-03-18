#include <stdlib.h>
// Vector3_int.h

struct Vector3;

// 1. Создание
struct Vector3* Zero();
struct Vector3* E_1(); // (1,0,0)
struct Vector3* E_2(); // (0,1,0)
struct Vector3* E_3(); // (0,0,1)
struct Vector3* From(int* values); 

// 2. Декомпозиция
int GetX(struct Vector3* vect);
int GetY(struct Vector3* vect);
int GetZ(struct Vector3* vect);
// int Get(struct Vector3* vect, int i); 
int GetNorm(); // (????)

// 3. Операции
struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2);
int Mult(struct Vector3* v1, struct Vector3* v2);
struct Vector3* MultSc(int scalar, struct Vector3* v2);

// Vector3_int.c

struct Vector3
{
	int x;
	int y;
	int z;
} Vector3;

struct Vector3* the_zero;

struct Vector3* Zero()
{
	//struct Vector3* zero = malloc(sizeof(struct Vector3));
	if (!the_zero) // мемоизация
	{
		the_zero =  malloc(sizeof(struct Vector3));
		the_zero->x = 0;
		the_zero->y = 0;
		the_zero->z = 0;
	}
	return the_zero;
}



int GetX(struct Vector3* vect)
{
	if (vect)
		return vect->x;
	raise(...);
}

struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2)
{
	struct Vector3* result = malloc(sizeof(struct Vector3));
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
	result->z = v1->z + v2->z;
	return result;
}

// а что если...
struct Vector3
{
	T x;
	T y;
	T z;
};

//НЕ РАБОТАЕТ!!!
struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2)
{
	struct Vector3* result = malloc(sizeof(struct Vector3));
	result->x = v1->x + v2->x; //???? не определен +
	result->y = v1->y + v2->y; //???? не определен +
	result->z = v1->z + v2->z; //???? не определен +
	return result;
}
// Тогда так:
struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2, T (*sum)(T,T))
{
	struct Vector3* result = malloc(sizeof(struct Vector3));
	result->x = sum(v1->x, v2->x); //???? не определен +
	result->y = sum(v1->y, v2->y); //???? не определен +
	result->z = sum(v1->z, v2->z); //???? не определен +
	return result;
}
