#include <iostream>
#include "Vector.h"
#include "Tuple.h"
#include <complex.h>
#include <time.h>
int main() {
    srand(time(nullptr));
    Tuple<Vector<int>, Vector<double>> tuple = {Vector<int>(), Vector<double>()};
    std::cout << "Выберите тип:" << std::endl;
    std::cout << "0 - integer, 1 - real, 2 - complex" << std::endl;
    int type;
    std::cin >> type;

    std::variant<Vector<int>, Vector<double>> vec;

    switch(type) {
        case 0:
            vec = tuple.Get<0>();
            break;
        case 1:
            vec = tuple.Get<1>();
        default:
            exit(1);
    }

    vec = std::visit()
    for(int i = 0; i < vec.GetLength())

    //auto lol = vec.index();
    //std::cout << lol << std::endl;

    return 0;
}