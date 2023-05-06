#include <iostream>
#include "Vector.h"
#include <complex.h>
#include "Complex.h"
#include <time.h>

template <typename T>
int main_t() {
    int length;
    std::cout << "Введите длину вектора: ";
    std::cin >> length;
    auto vec = Vector<T>(length);
    std::cout << "\n";
    for(int i = 0; i < vec.GetLength(); i++) {
        vec.InsertAt(i, rand() % 10);
    }

    for(int i = 0; i < vec.GetLength(); i++) {
        std::cout << "vec["<< i << "] = " << vec.Get(i) << std::endl;
    }

    std::cout << "Norm = " << vec.Norm() << std::endl;
    vec.VectorScal(2);
    for(int i = 0; i < vec.GetLength(); i++) {
        std::cout << "vec["<< i << "] = " << vec.Get(i) << std::endl;
    }
    auto vec2 = Vector<T>(vec);
    std::cout << "ScalarMult = " << vec.ScalarMult(&vec2) << std::endl;

    auto* add = vec.Sum(&vec2);
    for(int i = 0; i < add->GetLength(); i++) {
        std::cout << "add["<< i << "] = " << add->Get(i) << std::endl;
    }
    return 0;
}

int main() {
    srand(time(nullptr));
    std::cout << "Выберите хранимый тип:" << std::endl;
    std::cout << "0 - integer, 1 - real" << std::endl;
    int type;
    std::cin >> type;
    switch (type) {
    case 0:
        return main_t<int>();
    case 1:
        return main_t<double>();
    }
}