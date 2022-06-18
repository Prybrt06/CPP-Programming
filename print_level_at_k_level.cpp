#include<iostream>
#include "trees_using_vector.h"
using namespace std;

int main()
{
    // treeNode<int> *root = takeInput();
    treeNode<int>* root = takeInputLevelWise();
    // printTree(root);

    // printLevelWise(root);

    cout << "The height of the tree is : " << height_of_tree(root) << endl;
    int k;
    cout << "Enter the level : ";
    cin >> k;
    print_k_level(root,k);
}

/*
                      1
                    / | \
                   2  3  4
                 /  \                                   1 3 2 3 4 2 5 6 0 0 0 0
                5   6 
*/