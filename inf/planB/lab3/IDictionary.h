#include "Laba3.h"

template <class TKey, class TElement>
class IDictionary
{
private: 
	BinarySearchTree<TKey, TElement>* tree;

public:
    IDictionary()
    {
        tree = new BinarySearchTree<TKey, TElement>{};
    }
    ~IDictionary()
    {
        delete tree;
    }
    void Add(TKey key, TElement element)
    {
        tree->insert(key, element);
        return;
    }
    void Remove(TKey key)
    {
        tree->remove(key);
        return;
    }
    bool ContainsKey(TKey key)
    {        return tree->ContainsKey(key);
    }
    TElement& Get(TKey key)
    {
        return tree->Get(key);
    }
    int GetCount()
    {
        return tree->GetCount();
    }
    void PrintInOrder()
    {
        tree->inOrderTraversal();
    }
    void PrintPreOrder()
    {
        tree->preOrderTraversal();
    }
    void PrintPostOrder()
    {
        tree->postOrderTraversal();
    }
    TElement& operator[] (TKey index) 
    {
        return tree->Get(index);
    }
};