#include "Laba3.h"

int main(){
    
    int size = 100;
    int* arr = new int[size];
    for(int i = 0; i < size; ++i){
        arr[i] = rand() % 10;
    }

    GenerateSparseVector(size, arr);
    IDictionary<int, int>* dictSparceVector = new IDictionary<int, int>;
    CreateDictSparseVector(arr, size, dictSparceVector);
    dictSparceVector->PrintInOrder();

    //cout << "aa" << endl;

    return 0;
}