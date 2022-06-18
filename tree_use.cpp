#include<iostream>
#include "trees_using_vector.h"
using namespace std;

int main()
{
    // treeNode<int> *root = takeInput();
    treeNode<int>* root = takeInputLevelWise();
    // printTree(root);

    printLevelWise(root);

    treeNode<int>* secondLargestNode = getSecondLargestNode(root);

    cout << secondLargestNode->data << endl;
}
/*
                      1
                    / | \
                   2  3  4
                 /  \
                5   6 



 1 3 2 3 4 2 5 6 0 0 0 0

*/