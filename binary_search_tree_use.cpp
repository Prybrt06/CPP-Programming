#include<iostream>
#include "binary_search_tree_class.h"
using namespace std;


int main()
{
    BST* binarySearchTree = new BST();

    binarySearchTree->insert(7);

    binarySearchTree->insert(5);

    binarySearchTree->insert(10);

    binarySearchTree->insert(9);

    binarySearchTree->insert(2);

    binarySearchTree->insert(8);

    // binarySearchTree->print();

    // binarySearchTree->remove(2);

    binarySearchTree->print();

    cout << binarySearchTree->height() << endl;
}