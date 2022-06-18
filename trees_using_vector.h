#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class treeNode
{
public:
    T data;
    vector<treeNode<T>*> children;

    treeNode(T data)
    {
        this->data = data;
        //children.p;
    }

    ~treeNode()
    {
        for(int i=0;i<children.size();i++)
        {
            delete children[i];
        }
    }
};

treeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter Root Data : ";
    cin>>rootData;

    treeNode<int>* root = new treeNode<int>(rootData);

    queue<treeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "No of children of " << front->data << " : ";
        int numchild;
        cin>>numchild;

        for(int i=0;i<numchild;i++)
        {
            int childNode;
            cout << "No. "<< (i+1) <<" child of "<< front->data << " : " ;
            cin>>childNode;

            treeNode<int>* newNode = new treeNode<int>(childNode);

            pendingNodes.push(newNode);

            front->children.push_back(newNode);
        }
    }

    return root;
}

treeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter Data ";
    cin>>rootData;

    treeNode<int>* root = new treeNode<int>(rootData);

    int n;
    cout<<"No of children of "<<rootData<<" ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        treeNode<int>* newNode = takeInput();
        root->children.push_back(newNode);
    }

    return root;
}

void printLevelWise(treeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<treeNode<int>*> nodes;
    
    nodes.push(root);

    while(!nodes.empty())
    {
        treeNode<int>* front = nodes.front();

        cout << nodes.front()->data << " : ";

        for(int i=0;i< front->children.size();i++)
        {
            cout << front->children[i]->data << ", ";
            nodes.push(front->children[i]);
        }

        cout << endl;

        nodes.pop();
    }
}

void printTree(treeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" : ";

    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<", ";
    }

    cout<<endl;

    for(int i=0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}

void deleteTree(treeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    for(int i=0;i<root->children.size();i++)
    {
        deleteTree(root->children[i]);
    }

    delete root;
}

int height_of_tree(treeNode<int>* root)
{
    int max = 0;
    for(int i=0;i<root->children.size();i++)
    {
        int ans = height_of_tree(root->children[i]);

        if(ans>=max)
        {
            max = ans;
        }
    }

    return (max+1);
}

void print_k_level(treeNode<int>* root, int level)
{
    if(root==NULL)
    {
        return;
    }

    if(level==0)
    {
        cout << root->data << " ";
        return;
    }

    for(int i=0;i<root->children.size();i++)
    {
        print_k_level(root->children[i],level-1);
    }
}

treeNode<int>* getSecondLargestNode(treeNode<int>* root) {
    // Write your code here
    if(root==NULL)
    {
        return NULL;
    }

    if(root->children.size()==0)
    {
        return NULL;
    }

    int childCount = root->children.size();

    queue<treeNode<int>*> q;
    q.push(root);

    treeNode<int>* largest = new treeNode<int>(root->data);
    treeNode<int>* secondLargest = new treeNode<int>(INT_MIN);

    while(!q.empty())
    {
        treeNode<int>* current = q.front();
        q.pop();

        childCount = current->children.size();

        for(int i=0;i<childCount;i++)
        {
            q.push(current->children[i]);

            if(current->children[i]->data > largest->data)
            {
                secondLargest = largest;
                largest = current->children[i];
            }

            else if((current->children[i]->data < largest->data) && (current->children[i]->data > secondLargest->data))
            {
                secondLargest = current->children[i];
            }

            else if((current->children[i]->data == largest->data) || (current->children[i]->data == secondLargest->data))
            {
                continue;
            }
        }
    }

    return secondLargest;
}