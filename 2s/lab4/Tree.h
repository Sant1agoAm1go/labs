#pragma once
#include "Sequence.h"
#include "compare"
template <typename T> struct Node {
public:
    Sequence <T>* data;
    T key;
    struct Node *left;
    struct Node *right;

};

template <typename T> class Tree {
public:
    struct Node<T> *root;
};
