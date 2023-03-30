#include <iostream>
#include "DynamicArray.h"
#include <stdlib.h>
#include <time.h>
using namespace std; 
int main() {
    srand(time(NULL));
    int lenght = 10;
    DynamicArray<int> data = DynamicArray<int>(lenght);
    for(int i = 0; i < lenght; i++) {
        data.Set(i, rand () % 100);
        cout << "data[" << i << "] = " << data.Get(i) << endl;
    }
    return 0;
}