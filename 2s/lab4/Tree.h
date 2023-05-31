#pragma once
#include "Sequence.h"
template <typename T> struct Node {
public:
    T data;
    T key;
    struct Node *left;
    struct Node *right;
};

template <typename T>
void DeleteTree(Node<T>* node) {
        if(node != nullptr) {
            DeleteTree(node->left);
            DeleteTree(node->right);
            delete node;
        }
    }

template <typename T> class Tree {
private:
    struct Node<T> *root;

public:
    Tree() {
        this->root = nullptr;
    }

    ~Tree() {
        DeleteTree(this->root);
    }

    Node<T>* GetRoot() {
        return this->root;
    }

    Node<T>* AddNode(Node<T>* node, T key, T data) {
        if (node == nullptr) {
            node = new Node<T>;
            node->key = key;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
        } 
        else if(key < node->key) {
            node->left = AddNode(node->left, key, data);

        }
        else if(key > node->key) {
            node->right = AddNode(node->right, key, data);
        }

        return node;
    } 

    Node<T>* SearchElement(Node<T>* node, T key) {
        if(node->key == key) {
            return node;
        }
        else if(key < node->key) {
            return SearchElement(node->left, key);
        }
        else if(key > node->key) {
            return SearchElement(node->right, key);
        } 
        return nullptr;

    }

    void RootLeftRight(Node<T>* node) {
        if(node != nullptr) {
            std::cout << "{" << node->data << "}";
            RootLeftRight(node->left);
            RootLeftRight(node->right);
        }
    }

    void RightLeftRoot(Node<T>* node) {
        if(node != nullptr) {
            RootLeftRight(node->right);
            RootLeftRight(node->left);
            std::cout << "{" << node->data << "}";
        }
    }

    void LeftRootRight(Node<T>* node) {
        if(node != nullptr) {
            LeftRootRight(node->left);
            std::cout << "{" << node->data << "}";
            LeftRootRight(node->right);
            
        }
    }

    void RightRootLeft(Node<T>* node) {
        if(node != nullptr) {
            LeftRootRight(node->right);
            std::cout << "{" << node->data << "}";
            LeftRootRight(node->left);
            
        }
    }

    void LeftRightRoot(Node<T>* node) {
        if(node != nullptr ) {
            LeftRootRight(node->left);
            LeftRootRight(node->right);
            std::cout << "{" << node->data << "}";
            
            
        }
    }

    void RootRightLeft(Node<T>* node) {
        if(node != nullptr) {
            std::cout << "{" << node->data << "}";
            LeftRootRight(node->right);
            LeftRootRight(node->left);
        }
    }
};












/*template <typename T>
Node<T>* AddNode(Node<T>* node, T key, T data) {
        if (node == nullptr) {
            node = new Node<T>;
            node->key = key;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;

        } 
        else if(key < node->key) {
            node->left = AddNode(node->left, key, data);

        }
        else if(key > node->key) {
            node->right = AddNode(node->right, key, data);
        }

        return node;
        
}*/



/*Node() {
        data = nullptr;
        key = T();
        left = nullptr;
        right = nullptr;
    }

    ~Node();*/
