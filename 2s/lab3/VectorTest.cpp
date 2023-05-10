#include <iostream>
#include <cassert>
#include <time.h>
#include "Vector.h"
int main() {
    srand(time(nullptr));
    Vector<int> vec = Vector<int>(5);
    int data[] = {1,2,3,4,5};
    int data2[] = {6,7,8,9,0};
    Vector<int> vec2 = Vector<int>(data, sizeof(data)/sizeof(int));
    Vector<int> vec3 = Vector<int>(data2, sizeof(data2)/sizeof(int));
    Vector<int> vec4 = vec2 * 2;
    for(int i = 0; i < vec4.GetLength(); i++) {
        std::cout << vec4.Get(i) << std::endl;
    }

    for(int i = 0; i < vec2.GetLength(); i++) {
        std::cout << vec2.Get(i) << std::endl;
    }
    vec.InsertAt(0, 2);
    vec.InsertAt(1, 3);
    vec.InsertAt(2, 6);
    vec.InsertAt(3, 7);
    vec.InsertAt(4, 8);
    
    /*assert(vec.Norm() == 7);
    assert(vec[0] == 2);
    assert(vec[1] == 3);
    assert(vec[2] == 6);*/

    /*Vector<double> vec2 = Vector<double>(vec);
    for(double i = 0; i < vec.GetLength(); i++) {
        assert(vec2[i] == vec[i]); 
    }*/
    
    Vector<int> add = vec + vec2;
    for(int i = 0; i < add.GetLength(); i++) {
        std::cout << add.Get(i) << std::endl;
    }
    assert(add[0] == 3);
    assert(add[1] == 5);
    assert(add[2] == 9);
    assert(add[3] == 11);
    assert(add[4] == 13);
    add.VectorScal(2);
    assert(add[0] == 6);
    assert(add[1] == 10);
    assert(add[2] == 18);
    assert(add[3] == 22);
    assert(add[4] == 26);
    for(int i = 0; i < add.GetLength(); i++) {
        std::cout << add.Get(i) << std::endl;
    }

    return 0;
}