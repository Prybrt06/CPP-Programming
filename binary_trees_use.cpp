#include<iostream>
#include "binary_trees.h"
using namespace std;

int main()
{
    // BinaryTreesNode<int>* root = new BinaryTreesNode<int>(1);
    // BinaryTreesNode<int>* node1 = new BinaryTreesNode<int>(2);
    // BinaryTreesNode<int>* node2 = new BinaryTreesNode<int>(3);

    // root->left = node1;
    // root->right = node2;

    // BinaryTreesNode<int>* root = takeInput();

    BinaryTreesNode<int>* root = takeInputLevelWise();

    // printTree(root);

    // printBinaryTreeLevelWise(root);
    // cout << numberOfNodes(root) << endl;
    // mirrorTree(root);

    printLevelATNewLine(root);
    
    cout << endl;

    // pair<int,int> p = heightDiameter(root);
    // cout << "The height of the tree is : " << p.first << endl;
    // cout << "The diameter of the tree is : " << p.second << endl;

    // cout << minimum(root) << endl << maximum(root) << endl;

    vector<int>* getPath = getRootToNodePath(root,8);

    for(int i=0;i<getPath->size();i++)
    {
        cout << getPath->at(i) << " ";
    }

    delete root;
    delete getPath;

    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 8 -1 -1
