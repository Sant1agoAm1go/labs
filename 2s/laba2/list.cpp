#include <iostream>
#include "LinkedList.h"
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int lenght = 5;
    LinkedList<int>* data = new LinkedList<int>();
    for (int i = 0; i < lenght; i++) {
        data->Append(rand() % 100);
    }
    for (int i = 0; i < lenght; i++) {
        std::cout << data->Get(i) << std::endl;
    }
    delete data;
    return 0;
}