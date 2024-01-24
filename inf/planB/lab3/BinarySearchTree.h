#include "Laba3.h"


template <class TKey, class TElement>
class BinarySearchTree
{
private:
    struct Node {
        TKey key;
        TElement value;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insert(Node* node, TKey key, TElement value)
    {
        if (node == nullptr) {
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key, value);
        }
        else {
            node->value = value;
        }

        return node;
    }
    
    bool search(Node* node, TKey key) 
    {
        
        if (node == nullptr) {
            return false;
        }

        if (key == node->key) {
            return true;
        }
        else if (key < node->key) {
            return search(node->left, key);
        }
        else {
            return search(node->right, key);
        }
        
    }
    Node* deleteNode(Node* root, TKey key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }
    
    void print(Node* node) 
    {
        if (node != nullptr) {
            print(node->left);
            cout << node->key << " " << node->value << endl;
            //cout << node->key << " " << node->value << endl;
            print(node->right);
        }
    }

    TElement& Get(Node* node, TKey key) 
    {
        if (node == nullptr) 
        {
            throw std::out_of_range("");
        }

        if (key < node->key) 
        {
            return Get(node->left, key); 
        }
        else if (key > node->key) 
        {
            return Get(node->right, key);
        }
        else 
        {
            return node->value; 
        }
    }

    int GetCount(Node* node) 
    {
        if (node == nullptr) 
        {
            return 0; 
        }
        else 
        {
            return 1 + GetCount(node->left) + GetCount(node->right);
        }
    }

    bool ContainsKey(Node* node, TKey key) 
    {
        if (node == nullptr) {
            return false; 
        }
        else if (node->key == key) {
            return true; 
        }
        else if (key < node->key) {
            return ContainsKey(node->left, key);
        }
        else {
            return ContainsKey(node->right, key);
        }
    }

    void preOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->key << " " << node->value << endl;
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->key << " " << node->value << endl;
        
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversal(node->left);
        cout << "[" << node->key << "]" << " " << node->value  << endl;
        inOrderTraversal(node->right);
    }
public:
    BinarySearchTree() 
    {
        root = nullptr;
    }

    void insert(TKey key, TElement value)
    {
        root = insert(root, key, value);
    }
    
    bool search(TKey key) 
    {
        return search(root, key);
    }
    
    void remove(TKey key) 
    {
        deleteNode(root, key);
    }

    void print() 
    {
        inOrderTraversal(root);
    }

    TElement& Get(TKey key) 
    {
        return Get(root, key);
    }

    int GetCount() 
    {
        return GetCount(root);
    }

    bool ContainsKey(TKey key) 
    {
        return ContainsKey(root, key);
    }
    void preOrderTraversal()
    {
        preOrderTraversal(root);
    }
    void postOrderTraversal()
    {
        postOrderTraversal(root);
    }
    void inOrderTraversal()
    {
        inOrderTraversal(root);
    }
};