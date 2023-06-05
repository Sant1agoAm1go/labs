#include <iostream>
#include "Tree.h"
#include "ListSequence.h"
#include "time.h"
int mapper(int a) {
    return a*2;
}
int reducer(int a, int b) {
    return a+b;
}

bool wherer(int a) {
    return a % 2 != 0;
}

int main() { 
    srand(time(nullptr));
    Tree<int, int>* tree = new Tree<int, int>(); 
    tree->AddNode(tree->GetRoot(), 10, 10); 
    tree->AddNode(tree->GetRoot(), 5, 5);
    tree->AddNode(tree->GetRoot(), 3, 3);
    tree->AddNode(tree->GetRoot(), 20, 20); 
    tree->AddNode(tree->GetRoot(), 30, 30); 

    assert(tree->GetRoot()->key == 10);
    assert(tree->GetRoot()->left->key == 5);
    assert(tree->GetRoot()->left->left->key == 3);
    assert(tree->GetRoot()->right->key == 20);
    assert(tree->GetRoot()->right->right->key == 30);

    Tree<int, int>* map_tree = tree->Map(mapper);
    assert(map_tree->GetRoot()->key == 20);
    assert(map_tree->GetRoot()->left->key == 10);
    assert(map_tree->GetRoot()->left->left->key == 6);
    assert(map_tree->GetRoot()->right->key == 40);
    assert(map_tree->GetRoot()->right->right->key == 60);

    Tree<int, int>* sub_tree1 = map_tree->GetSubTree(map_tree->GetRoot()->left);
    assert(sub_tree1->GetRoot()->key == 10);
    assert(sub_tree1->GetRoot()->left->key == 6);

    Tree<int, int>* sub_tree2 = map_tree->GetSubTree(map_tree->GetRoot()->right);
    assert(sub_tree2->GetRoot()->key == 40);
    assert(sub_tree2->GetRoot()->right->key == 60);

    Tree<int, int>* where_tree = tree->Where(wherer);
    assert(where_tree->GetRoot()->key == 5);
    assert(where_tree->GetRoot()->left->key == 3);

    int start = 0;
    assert(tree->Reduce(tree->GetRoot(), reducer, start) == 68);

    Tree<int, int>* test = new Tree<int, int>();
    test->AddNode(test->GetRoot(), 4, 4); 
    test->AddNode(test->GetRoot(), 6, 6);
    test->AddNode(test->GetRoot(), 7, 7);
    test->AddNode(test->GetRoot(), 8, 8); 
    test->AddNode(test->GetRoot(), 9, 9); 

    Tree<int, int>* concat_tree = tree->Concat(test);

    std::cout << "Test completed successfully" << std::endl;
    delete tree;
    delete map_tree;
    delete sub_tree1;
    delete sub_tree2;
    delete where_tree;
    delete test;
    delete concat_tree;
    return 0;
}

/*int data1[] = {1,2,3,4,5};
    int data2[] = {6,7,8,9,0};
    int data3[] = {2,4,6,8,0};

    Tree<int, int>* tree = new Tree<int, int>;
    tree->root = new Node<int, int>;
    tree->root->data = 100;
    tree->root->key = 2;

    Node<int, int>* test1 = new Node<int, int>;
    test1->data = 10;
    test1->key = 1;
    test1->left = nullptr;
    test1->right = nullptr;

    Node<int, int>* test2 = new Node<int, int>;
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


/*Node<int, int>* root = new Node<int, int>;
    Node<int, int>* left_tree = new Node<int, int>;
    left_tree->left = nullptr;
    left_tree->right = nullptr;
    Node<int, int>* right_tree = new Node<int, int>;
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