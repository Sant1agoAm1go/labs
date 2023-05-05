#include <iostream>
#include "Vector.h"
#include <complex.h>
#include <time.h>

template <typename T>
int main_t() {
    int length;
    std::cin >> length;
    auto vec = Vector<T>(length);

    for(int i = 0; i < vec.GetLength(); i++) {
        vec.InsertAt(i, rand() % 100);
    }
    for(int i = 0; i < vec.GetLength(); i++) {
        std::cout << vec.Get(i) << std::endl;
    }
    return 0;
}

int main() {
    srand(time(nullptr));
    std::cout << "Выберите тип:" << std::endl;
    std::cout << "0 - integer, 1 - real, 2 - complex" << std::endl;
    int type;
    std::cin >> type;
    switch (type)
    {
    case 0:
        return main_t<int>();
    case 1:
        return main_t<double>();
    }
}