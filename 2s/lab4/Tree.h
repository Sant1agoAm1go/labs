#include "Sequence.h"
template <typename T> struct Node {
public:
    T* data;
    struct Node *left;
    struct Node *right;

};