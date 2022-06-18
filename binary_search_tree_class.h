#include<iostream>
#include<queue>
#include<climits>
#include "binary_trees.h"
using namespace std;

class BST
{
    BinaryTreesNode<int>* root;

  public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

  private:
    void printPrivate(BinaryTreesNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }

        queue<BinaryTreesNode<int>*> q;
        q.push(root);

        while(!q.empty())
        {
            BinaryTreesNode<int>* front = q.front();
            q.pop();

            cout<<front->data<<":";

            if(front->left)
            {
                q.push(front->left);
                cout<<"L:"<<front->left->data;
            }

            if(front->right)
            {
                q.push(front->right);
                cout<<",R:"<<front->right->data;
            }

            cout<<endl;
        }
    }

  public:
    void print()
    {
        printPrivate(root);
        // printBinaryTreeLevelWise(root);
    }

  private:
    BinaryTreesNode<int>* insertDataPrivate(BinaryTreesNode<int>* root,int data)
    {
        if(root==NULL)
        {
            BinaryTreesNode<int>* ans = new BinaryTreesNode<int>(data);
            return ans;
        }

        if(data>=(root->data))
        {
            BinaryTreesNode<int>* right = insertDataPrivate(root->right,data);
            root->right = right;
        }

        else if(data<(root->data))
        {
            BinaryTreesNode<int>* left = insertDataPrivate(root->left,data);
            root->left = left;
        }

        return root;
    }

  public:
    void insert(int data)
    {
        root = insertDataPrivate(root,data);
    }

  private:
    bool isPresentPrivate(int data,BinaryTreesNode<int>* node)
    {
        if(node==NULL)
        {
            return false;
        }

        bool check;
        
        if((node->data)==data)
        {
            return true;
        }

        else if(data < (node->data))
        {
            check = isPresentPrivate(data,node->left);
        }

        else if(data > (node->data))
        {
            check = isPresentPrivate(data,node->right);
        }

        return check;
    }

  public:
    bool isPresent(int data)
    {
        return isPresentPrivate(data,root);
    }

  private:
    int minima(BinaryTreesNode<int>* root)
    {
        if(root==NULL)
        {
            return INT_MAX;
        }

        return min(root->data,min(minima(root->left),minima(root->right)));
    }

    BinaryTreesNode<int>* removePrivate(BinaryTreesNode<int>* root,int key)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if(root->data > key)
        {
            root->left = removePrivate(root->left,key);

            return root;
        }

        else if(root->data < key)
        {
            root->right = removePrivate(root->right,key);

            return root;
        }

        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }

            else if(root->right==NULL)
            {
                BinaryTreesNode<int>* newRoot = root->left;
                root->left = NULL;
                delete root;
                return newRoot;
            }

            else if(root->left==NULL)
            {
                BinaryTreesNode<int>* newRoot = root->right;
                root->right = NULL;
                delete root;
                return newRoot;
            }

            else if(root->left!=NULL && root->right!=NULL)
            {
                BinaryTreesNode<int>* minNode = root->right;

                while(minNode->left != NULL)
                {
                    minNode = minNode->left;
                }

                int rightMin = minNode->data;
                root->data = rightMin;

                root->right = removePrivate(root->right,rightMin);

                return root;
            }
        }
        return root;
    }

  public:
    void remove(int data)
    {
        root = removePrivate(root,data);
    }

  private:
    int heightPrivate(BinaryTreesNode<int>* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        return 1 + max(heightPrivate(root->left),heightPrivate(root->right));
    }

  public:
    int height()
    {
        return heightPrivate(root);
    }
};