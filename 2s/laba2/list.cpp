#include <iostream>
#include "LinkedList.h"
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int lenght = 5;
    LinkedList<int>* data = new LinkedList<int>();
    (*data).Append(rand() % 10);
    data->LinkedList_print();
    delete data;
    return 0;
}