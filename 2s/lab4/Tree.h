#pragma once
#include "Sequence.h"
template <typename T> struct Node {
public:
    T key;
    T data;
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
    Node<T> *root;

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
    void SetRoot(Node<T>* new_root) {
        this->root = new_root;
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
        this->root = node;
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
            RightLeftRoot(node->right);
            RightLeftRoot(node->left);
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
            RightRootLeft(node->right);
            std::cout << "{" << node->data << "}";
            RightRootLeft(node->left);
            
        }
    }

    void LeftRightRoot(Node<T>* node) {
        if(node != nullptr ) {
            LeftRightRoot(node->left);
            LeftRightRoot(node->right);
            std::cout << "{" << node->data << "}";
            
            
        }
    }

    void RootRightLeft(Node<T>* node) {
        if(node != nullptr) {
            std::cout << "{" << node->data << "}";
            RootRightLeft(node->right);
            RootRightLeft(node->left);
        }
    }

    Tree<T>* Mapper(Node<T>* node, Node<T>* res_node, T (*func)(T), Tree<T>* result) {
        if(node != nullptr) {
        res_node = result->AddNode(res_node, node->key, func(node->data));
        result = Mapper(node->left, res_node, func, result);
        result = Mapper(node->right, res_node, func, result);
        }
        return result;
    } 

    Tree<T>* Map(T (*func)(T)) {
        Tree<T>* result = new Tree<T>();
        Node<T>* res_root = result->GetRoot();
        result = Mapper(this->root, res_root, func, result);
        return result;
    }

    Tree<T>* Wherer(Node<T>* node, Node<T>* res_node, T (*func)(T), Tree<T>* result) {
        if(node != nullptr && func(node->data)) {
        res_node = result->AddNode(res_node, node->key, node->data);
        result = Wherer(node->left, res_node, func, result);
        result = Wherer(node->right, res_node, func, result);
        }
        return result;
    } 

    Tree<T>* Where(bool (*func)(T)) {
        Tree<T>* result = new Tree<T>();
        Node<T>* res_root = result->GetRoot();
        result = Wherer(this->root, res_root, func, result);
        return result;
    }
    T Reduce(Node<T>* node, T (*func)(T,T), T start) {
        if(node != nullptr ) {
            start = func(node->data, start);
            Reduce(node->left->data, start);
            Reduce(node->right->data, start);
        }
		return start;
	}

    Tree<T>* Mergerer(Node<T>* node1, Node<T>* node2, Node<T>* res_node, Tree<T>* result) {
        if(node1 != nullptr)
            res_node = result->AddNode(res_node, node1->key, node1->data);
        if(node2 != nullptr && node1->key != node2->key) 
            res_node = result->AddNode(res_node, node2->key, node2->data);
        result = Mergerer(node1->left, node2->left, res_node, result);
        result = Mergerer(node1->right, node2->right, res_node, result);
        return result;
    } 

    Tree<T>* Merge(Tree<T>* tree1, Tree<T>* tree2) {
        Tree<T>* result = new Tree<T>();
        Node<T>* res_root = result->GetRoot();
        result = Mergerer(tree1->GetRoot(), tree2->GetRoot(), res_root, result);
        return result;
    }

    Tree<T>* Concater(Node<T>* node1, Node<T>* node2, Node<T>* res_node, Tree<T>* result) {
        if(node1 != nullptr)
            res_node = result->AddNode(res_node, node1->key, node1->data);
        if(node2 != nullptr) 
            res_node = result->AddNode(res_node, node2->key, node2->data);
        result = Mergerer(node1->left, node2->left, res_node, result);
        result = Mergerer(node1->right, node2->right, res_node, result);
        return result;
    } 

    Tree<T>* Concat(Tree<T>* tree1, Tree<T>* tree2) {
        Tree<T>* result = new Tree<T>();
        Node<T>* res_root = result->GetRoot();
        result = Mergerer(tree1->GetRoot(), tree2->GetRoot(), res_root, result);
        return result;
    }

    Tree<T>* SubTree(Node<T>* node, Node<T>* res_node, Tree<T>* result) {
        if(node != nullptr) {
            res_node = result->AddNode(res_node, node->key, node->data);
            result = SubTree(node->left, res_node, result);
            result = SubTree(node->right, res_node, result);
        } 
        return result;

    }

    Tree<T>* GetSubTree(Node<T>* node) {
        Tree<T>* result = new Tree<T>();
        Node<T>* res_root = result->GetRoot();
        result = SubTree(node, res_root, result);
        return result;
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
