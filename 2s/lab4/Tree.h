#pragma once
#include "Sequence.h"
#include <concepts> 
#include "Complex.h"
template< class Tkey>
concept SameHelper = std::same_as<Tkey, int> || std::same_as<Tkey, double> || std::same_as<Tkey, float> ||  std::same_as<Tkey, complex>;
 
template <SameHelper Tkey, typename Tdata> 
struct Node {
    public:
        Tkey key;
        Tdata data;
        struct Node *left;
        struct Node *right;
};

template <typename Tkey, typename Tdata>
void DeleteTree(Node<Tkey, Tdata>* node) {
    if(node != nullptr) {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
}

template <typename Tkey, typename Tdata> class Tree {
private:
    Node<Tkey, Tdata> *root;

public:
    Tree() {
        this->root = nullptr;
    }

    Tree(Tkey key, Tdata data) {
        this->root->key = key;
        this->root->data = data;
        this->root->left = nullptr;
        this->root->right = nullptr;
    }

    ~Tree() {
        DeleteTree(this->root);
    }

    Node<Tkey, Tdata>* GetRoot() {
        return this->root;
    }
    void SetRoot(Node<Tkey, Tdata>* new_root) {
        this->root = new_root;
    }

    Node<Tkey, Tdata>* AddNode(Node<Tkey, Tdata>* node, Tkey key, Tdata data) {
        if (node == nullptr) {
            node = new Node<Tkey, Tdata>;
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
        if(root == nullptr) {
            this->root = node;
        }
        return node;
    } 


    Node<Tkey, Tdata>* SearchElement(Node<Tkey, Tdata>* node, Tkey key) {
        if(node != nullptr) {
            if(node->key == key) {
                return node;
            }
            else if(key < node->key) {
                return SearchElement(node->left, key);
            }
            else if(key > node->key) {
                return SearchElement(node->right, key);
            }
        }
        return nullptr;
    }

    Node<Tkey, Tdata>* SearchMin(Node<Tkey, Tdata>* node) {
        if(node->left == nullptr) {
            return node;
        }
        return SearchMin(node->left);
    }

    Node<Tkey, Tdata>* SearchMax(Node<Tkey, Tdata>* node) {
        if(node->right == nullptr) {
            return node;
        }
        return SearchMax(node->right);
    }

    void RootLeftRight(Node<Tkey, Tdata>* node) {
        if(node != nullptr) {
            std::cout << "{" << node->key << ": " << node->data << "}";
            RootLeftRight(node->left);
            RootLeftRight(node->right);
        }
    }

    void RightLeftRoot(Node<Tkey, Tdata>* node) {
        if(node != nullptr) {
            RightLeftRoot(node->right);
            RightLeftRoot(node->left);
            std::cout << "{" << node->key << ": " << node->data << "}";
        }
    }

    void LeftRootRight(Node<Tkey, Tdata>* node) {
        if(node != nullptr) {
            LeftRootRight(node->left);
            std::cout << "{" << node->key << ": " << node->data << "}";
            LeftRootRight(node->right);
            
        }
    }

    void RightRootLeft(Node<Tkey, Tdata>* node) {
        if(node != nullptr) {
            RightRootLeft(node->right);
            std::cout << "{" << node->key << ": " << node->data << "}";
            RightRootLeft(node->left);
            
        }
    }

    void LeftRightRoot(Node<Tkey, Tdata>* node) {
        if(node != nullptr ) {
            LeftRightRoot(node->left);
            LeftRightRoot(node->right);
            std::cout << "{" << node->key << ": " << node->data << "}";
            
            
        }
    }

    void RootRightLeft(Node<Tkey, Tdata>* node) {
        if(node != nullptr) {
            std::cout << "{" << node->key << ": " << node->data << "}";
            RootRightLeft(node->right);
            RootRightLeft(node->left);
        }
    }

    friend void Mapper(Node<Tkey, Tdata>* node, Tkey (*func)(Tkey), Tree<Tkey, Tdata>* result) {
        if(node != nullptr) {
            result->AddNode(result->GetRoot(), func(node->key), node->data);
            Mapper(node->left, func, result);
            Mapper(node->right, func, result);
        }
    }

    Tree<Tkey, Tdata>* Map(Tkey (*func)(Tkey)) {
        Tree<Tkey, Tdata>* result = new Tree<Tkey, Tdata>();
        Mapper(this->root, func, result);
        return result;
    }

    friend void Wherer(Node<Tkey, Tdata>* node, bool (*func)(Tkey), Tree<Tkey, Tdata>* result) {
        if(node != nullptr) {
            if(func(node->key)) {
                result->AddNode(result->GetRoot(), node->key, node->data);
            }
            Wherer(node->left, func, result);
            Wherer(node->right, func, result);
        }
    } 

    Tree<Tkey,Tdata>* Where(bool (*func)(Tkey)) {
        Tree<Tkey, Tdata>* result = new Tree<Tkey, Tdata>();
        Wherer(this->root, func, result);
        return result;
    }

    Tkey& Reduce(Node<Tkey, Tdata>* node, Tkey (*func)(Tkey, Tdata), Tkey& start) {
        if(node != nullptr ) {
            start = func(node->data, start);
            Reduce(node->left, func, start);
            Reduce(node->right, func, start);
        }
        return start;
	}

   friend void Mergerer(Node<Tkey, Tdata>* node1, Node<Tkey, Tdata>* node2, Tree<Tkey, Tdata>* result) {
        if(node1 != nullptr && node2 != nullptr) {
            result->AddNode(result->GetRoot(), node1->key, node1->data);
            if(node1->data != node2->data) {
                result->AddNode(result->GetRoot(), node2->key, node2->data);
            }
            Mergerer(node1->left, node2->left, result);
            Mergerer(node1->right, node2->right, result);
        }
    } 

    Tree<Tkey, Tdata>* Merge(Tree<Tkey, Tdata>* other) {
        Tree<Tkey, Tdata>* result = new Tree<Tkey, Tdata>();
        Mergerer(this->GetRoot(), other->GetRoot(), result);
        return result;
    }

    friend void Concater(Node<Tkey, Tdata>* node, Tree<Tkey, Tdata>* result) {
        if(node != nullptr) {
            result->AddNode(result->GetRoot(), node->key, node->data);
            Concater(node->left, result);
            Concater(node->right, result);
        }
    } 

    Tree<Tkey, Tdata>* Concat(Tree<Tkey, Tdata>* other) {
        Tree<Tkey, Tdata>* result = new Tree<Tkey, Tdata>();
        Concater(this->GetRoot(), result);
        Concater(other->GetRoot(), result);
        return result;
    }

    friend void SubTree(Node<Tkey, Tdata>* node, Tree<Tkey, Tdata>* result) {
        if(node != nullptr) {
            result->AddNode(result->GetRoot(), node->key, node->data);
            SubTree(node->left, result);
            SubTree(node->right, result);
        } 
    }

    Tree<Tkey, Tdata>* GetSubTree(Node<Tkey, Tdata>* node) {
        Tree<Tkey, Tdata>* result = new Tree<Tkey, Tdata>();
        SubTree(node, result);
        return result;
    }
};












/*template <typename T>
Node<Tkey,Tdata>* AddNode(Node<T>* node, T key, T data) {
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
