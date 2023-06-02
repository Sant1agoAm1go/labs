#include <iostream>
#include "Tree.h"
#include "ListSequence.h"
#include "time.h"
int func(int a) {
    return a*2;
}
int main() {
    srand(time(nullptr));
    Tree<int>* tree = new Tree<int>(); 
    Node<int>* root = tree->GetRoot();
    root = tree->AddNode(root, 10, 100); 
    root = tree->AddNode(root, 5, 50);
    root = tree->AddNode(root, 3, 30);
    root = tree->AddNode(root, 20, 200); 
    root = tree->AddNode(root, 30, 300); 
    tree->LeftRootRight(root);

    std::cout << "\ndouble map_tree: ";
    Tree<int>* map_tree = tree->Map(func);
    map_tree->LeftRootRight(map_tree->GetRoot());
    std::cout <<"\nleft sub_tree: ";
    Tree<int>* sub_tree1 = map_tree->GetSubTree(map_tree->GetRoot()->left);
    sub_tree1->LeftRootRight(sub_tree1->GetRoot());
    std::cout <<"\nroot: " << "{" << map_tree->GetRoot()->data << "}";
    std::cout <<"\nright sub_tree: ";
    Tree<int>* sub_tree2 = map_tree->GetSubTree(map_tree->GetRoot()->right);
    sub_tree2->LeftRootRight(sub_tree2->GetRoot());
    std::cout << " \n" << "Test completed successfully" << std::endl;
    delete tree;
    delete map_tree;
    delete sub_tree1;
    delete sub_tree2;
    return 0;
}

/*int data1[] = {1,2,3,4,5};
    int data2[] = {6,7,8,9,0};
    int data3[] = {2,4,6,8,0};

    Tree<int>* tree = new Tree<int>;
    tree->root = new Node<int>;
    tree->root->data = 100;
    tree->root->key = 2;

    Node<int>* test1 = new Node<int>;
    test1->data = 10;
    test1->key = 1;
    test1->left = nullptr;
    test1->right = nullptr;

    Node<int>* test2 = new Node<int>;
    test2->data = 50;
    test2->key = 3;
    test2->left = nullptr;
    test2->right = nullptr;

    if(test1->key < tree->root->key) {
        tree->root->left = test1;
    }
    else if(test1->key > tree->root->key) {
        tree->root->right = test1;
    }
    if(test2->key < tree->root->key) {
       tree->root->left= test2;
    }
    else if(test2->key > tree->root->key) {
        tree->root->right = test2;
    }
    std::cout << "{";
    for(int i = 0; i < tree->root->left->data->GetLength()-1; i++) {
    std::cout << tree->root->left->data->Get(i) << ", "; 
    }
    std::cout << tree->root->left->data->GetLast() << "} "; 

    std::cout << "{";
    for(int i = 0; i < tree->root->data->GetLength()-1; i++) {
    std::cout << tree->root->data->Get(i) << ", "; 
    }
    std::cout << tree->root->data->GetLast() << "} "; 

    std::cout << "{";
    for(int i = 0; i < tree->root->right->data->GetLength()-1; i++) {
    std::cout << tree->root->right->data->Get(i) << ", "; 
    }
    std::cout << tree->root->right->data->GetLast() << "} ";
    std::cout << "{" << tree->root->left->data << "}";
    std::cout << "{" << tree->root->data << "}";
    std::cout << "{" << tree->root->right->data << "}";
    delete tree;
    delete test1;
    delete test2;*/


/*Node<int>* root = new Node<int>;
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
    std::cout << right_tree->data[4] << "} ";*/