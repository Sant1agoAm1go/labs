#include <iostream>
#include "Tree.h"
int main() {
    int data1[] = {1,2,3,4,5};
    int data2[] = {6,7,8,9,0};
    int data3[] = {2,4,6,8,0};
    Node<int>* root = new Node<int>;
    Node<int>* left_tree = new Node<int>;
    left_tree->left = nullptr;
    left_tree->right = nullptr;
    Node<int>* right_tree = new Node<int>;
    left_tree->left = nullptr;
    left_tree->right = nullptr;
    root->data = data1;
    root->left = left_tree;
    root->right = right_tree;
    left_tree->data = data2;
    right_tree->data = data3;

    std::cout << "{";
    for(int i = 0; i < 4; i++) {
        std::cout << left_tree->data[i] << ", ";
    }
    std::cout << left_tree->data[4] << "} ";

    std::cout << "{";
    for(int i = 0; i < 4; i++) {
        std::cout << root->data[i] << ", ";
    }
    std::cout << root->data[4] << "} ";

    std::cout << "{";
    for(int i = 0; i < 4; i++) {
        std::cout << right_tree->data[i] << ", ";
    }
    std::cout << right_tree->data[4] << "} ";

    return 0;
}