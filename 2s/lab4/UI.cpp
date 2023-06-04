#include <iostream>
#include "Tree.h"
#include "ListSequence.h"
#include "Complex.h"
#include "time.h"
template <typename Tdata>
Tdata mapper(Tdata a) {
    return a*2;
}

template <typename Tdata>
Tdata reducer(Tdata a, Tdata b) {
    return a+b;
}

template <typename Tdata>
bool wherer(Tdata a) {
    return a > 10;
}

template <typename Tkey, typename Tdata>
int main_t() {
    srand(time(nullptr));
    Tree<Tkey, Tdata>* tree = new Tree<Tkey, Tdata>(); 
    Node<Tkey, Tdata>* root = tree->GetRoot();
    root = tree->AddNode(root, 10, 10); 
    root = tree->AddNode(root, 5, 5);
    root = tree->AddNode(root, 3, 3);
    root = tree->AddNode(root, 20, 20); 
    root = tree->AddNode(root, 30, 30); 
    std::cout << "start tree: ";
    tree->LeftRootRight(root);

    std::cout << "\ndouble map_tree: ";
    Tree<Tkey, Tdata>* map_tree = tree->Map(mapper);
    map_tree->LeftRootRight(map_tree->GetRoot());

    std::cout <<"\nleft sub_tree: ";
    Tree<Tkey, Tdata>* sub_tree1 = map_tree->GetSubTree(map_tree->GetRoot()->left);
    sub_tree1->LeftRootRight(sub_tree1->GetRoot());

    std::cout << "\nroot: {" << map_tree->GetRoot()->key << ": " << map_tree->GetRoot()->data << "}";
    //std::cout <<"\nroot: " << "{" << map_tree->GetRoot()->data << "}";

    std::cout <<"\nright sub_tree: ";
    Tree<Tkey, Tdata>* sub_tree2 = map_tree->GetSubTree(map_tree->GetRoot()->right);
    sub_tree2->LeftRootRight(sub_tree2->GetRoot());

    std::cout <<"\nwhere_tree: ";
    Tree<Tkey, Tdata>* where_tree = tree->Where(wherer);
    where_tree->LeftRootRight(where_tree->GetRoot());

    Tdata start = Tdata();
    std::cout << "\nreduce sum of start tree: " << tree->Reduce(tree->GetRoot(), reducer, start);

    std::cout << "\ntest tree: ";
    Tree<Tkey, Tdata>* test = new Tree<Tkey, Tdata>();
    test->AddNode(test->GetRoot(), 4, 4); 
    test->AddNode(test->GetRoot(), 6, 6);
    test->AddNode(test->GetRoot(), 7, 7);
    test->AddNode(test->GetRoot(), 8, 8); 
    test->AddNode(test->GetRoot(), 9, 9); 
    test->LeftRootRight(test->GetRoot());

    std::cout << "\nconcatenation of start and test trees: ";
    Tree<Tkey, Tdata>* concat_tree = tree->Concat(test);
    concat_tree->LeftRootRight(concat_tree->GetRoot());

    std::cout << " \n" << "Test completed successfully" << std::endl;
    delete tree;
    delete map_tree;
    delete sub_tree1;
    delete sub_tree2;
    delete where_tree;
    delete test;
    delete concat_tree;
    return 0;
}

int main() {
    srand(time(nullptr));
    std::cout << "Choose stored type for key and data:" << std::endl;
    std::cout << "0 - integer, 1 - real" << std::endl;
    int type;
    std::cin >> type;
    switch (type) {
    case 0:
        return main_t<int, int>();
    case 1:
        return main_t<double, double>();
    }
    /*case 2:
        return main_t<complex, complex>();
    }*/


}

/*int main() { 
    srand(time(nullptr));
    Tree<Tkey, Tdata>* tree = new Tree<Tkey, Tdata>(); 
    Node<Tkey, Tdata>* root = tree->GetRoot();
    root = tree->AddNode(root, 10, 10); 
    root = tree->AddNode(root, 5, 5);
    root = tree->AddNode(root, 3, 3);
    root = tree->AddNode(root, 20, 20); 
    root = tree->AddNode(root, 30, 30); 
    std::cout << "\nstart tree: ";
    tree->LeftRootRight(root);

    std::cout << "\ndouble map_tree: ";
    Tree<Tkey, Tdata>* map_tree = tree->Map(mapper);
    map_tree->LeftRootRight(map_tree->GetRoot());

    std::cout <<"\nleft sub_tree: ";
    Tree<Tkey, Tdata>* sub_tree1 = map_tree->GetSubTree(map_tree->GetRoot()->left);
    sub_tree1->LeftRootRight(sub_tree1->GetRoot());

    std::cout << "\nroot: {" << map_tree->GetRoot()->key << ": " << map_tree->GetRoot()->data << "}";
    //std::cout <<"\nroot: " << "{" << map_tree->GetRoot()->data << "}";

    std::cout <<"\nright sub_tree: ";
    Tree<Tkey, Tdata>* sub_tree2 = map_tree->GetSubTree(map_tree->GetRoot()->right);
    sub_tree2->LeftRootRight(sub_tree2->GetRoot());

    std::cout <<"\nwhere_tree: ";
    Tree<Tkey, Tdata>* where_tree = tree->Where(wherer);
    where_tree->LeftRootRight(where_tree->GetRoot());

    int start = 0;
    std::cout << "\nreduce sum of start tree: " << tree->Reduce(tree->GetRoot(), reducer, start);

    std::cout << "\ntest tree: ";
    Tree<Tkey, Tdata>* test = new Tree<Tkey, Tdata>();
    test->AddNode(test->GetRoot(), 4, 4); 
    test->AddNode(test->GetRoot(), 6, 6);
    test->AddNode(test->GetRoot(), 7, 7);
    test->AddNode(test->GetRoot(), 8, 8); 
    test->AddNode(test->GetRoot(), 9, 9); 
    test->LeftRootRight(test->GetRoot());

    std::cout << "\nconcatenation of start and test trees: ";
    Tree<Tkey, Tdata>* concat_tree = tree->Concat(test);
    concat_tree->LeftRootRight(concat_tree->GetRoot());

    std::cout << " \n" << "Test completed successfully" << std::endl;
    delete tree;
    delete map_tree;
    delete sub_tree1;
    delete sub_tree2;
    delete where_tree;
    delete test;
    delete concat_tree;
    return 0;
}*/