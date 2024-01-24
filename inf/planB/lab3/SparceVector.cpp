#include "Laba3.h"

void GenerateSparseVector(int size, int* arr) {
    std::vector<int> sparseVector;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            sparseVector.push_back(arr[i]);
        }
    }
    return;
}

void CreateDictSparseVector(int* sparceVector, int size, IDictionary<int, int>* dict)
{
	for (int i = 0; i < size; i++)
	{
		if (sparceVector[i] != 0)  dict->Add(i, sparceVector[i]);
	}
}