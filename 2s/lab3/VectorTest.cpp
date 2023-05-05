#include <iostream>
#include <cassert>
#include <time.h>
#include "Vector.h"
int main() {
    srand(time(nullptr));
    Vector<double> vec = Vector<double>(3);
    vec.InsertAt(0, 2);
    vec.InsertAt(1, 3);
    vec.InsertAt(2, 6);
    assert(vec.VectorNorm() == 7);
    assert(vec[0] == 2);
    assert(vec[1] == 3);
    assert(vec[2] == 6);

    Vector<double> vec2 = Vector<double>(vec);
    for(double i = 0; i < vec.GetLength(); i++) {
        assert(vec2[i] == vec[i]); 
    }
    
    Vector<double> add = vec + vec2;
    assert(add[0] == 4);
    assert(add[1] == 6);
    assert(add[2] == 12);
    add.VectorScal(2);
    assert(add[0] == 8);
    assert(add[1] == 12);
    assert(add[2] == 24);

    return 0;
}