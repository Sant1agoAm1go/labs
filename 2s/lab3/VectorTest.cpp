#include <iostream>
#include <cassert>
#include <time.h>
#include "Vector.h"
int main() {
    srand(time(nullptr));
    Vector<int> vec = Vector<int>(5);
    int data[] = {1,2,3,4,5};
    int data2[] = {6,7,8,9,0};
   // Vector<int> vec2 = Vector<int>(data, sizeof(data)/sizeof(int));
    Vector<int> vec3 = Vector<int>(data2, sizeof(data2)/sizeof(int));
    Vector<int> vec4 = vec3 * 2;
    
    vec.InsertAt(0, 2);
    vec.InsertAt(1, 3);
    vec.InsertAt(2, 6);
    vec.InsertAt(3, 7);
    vec.InsertAt(4, 8);
    
    assert(vec[0] == 2);
    assert(vec[1] == 3);
    assert(vec[2] == 6);
    assert(vec[3] == 7);
    assert(vec[4] == 8);
    Vector<int> vec2 = vec;
    for(int i = 0; i < vec.GetLength(); i++) {
        assert(vec2[i] == vec[i]); 
    }
    
    Vector<int> add = vec + vec2;
    assert(add[0] == 4);
    assert(add[1] == 6);
    assert(add[2] == 12);
    assert(add[3] == 14);
    assert(add[4] == 16);

    add.VectorScal(2);
    assert(add[0] == 8);
    assert(add[1] == 12);
    assert(add[2] == 24);
    assert(add[3] == 28);
    assert(add[4] == 32);

    int items[] = {2,3,6};
    Vector<int> norm = Vector<int>(items, 3);
    assert(norm.Norm() == 7);
    assert(add.ScalarMult(&vec) == 648);
    std::cout << "Тесты пройдены успешно :)" << std::endl;
    return 0;
}