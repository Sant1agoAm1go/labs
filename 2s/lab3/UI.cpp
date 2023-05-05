#include <iostream>
#include "Vector.h"
#include <complex.h>
#include <time.h>
int main() {
    srand(time(nullptr));
    std::cout << "Выберите тип:" << std::endl;
    std::cout << "1 - integer, 2 - real, 3 - complex" << std::endl;
    int type, int length;
    std::cin >> type >> length;
    Vector<int> vec1 = Vector<int>(length);
    if(type == 2) Vector<double> vec = Vector<double>(length);
    if(type == 3) Vector<_complex> vec = Vector<_complex>(length);   
    for(int i = 0; i < vec.)
    return 0;
}