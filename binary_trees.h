#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class BinaryTreesNode
{
  public: 
    T data;
    BinaryTreesNode<T>* left;
    BinaryTreesNode<T>* right;
    BinaryTreesNode<T>* parent;

    BinaryTreesNode(T value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreesNode()
    {
        delete left;
        delete right;
    }
};

class isBSTReturn
{
  public:
    int minimum;
    int maximum;
    bool isBST;
};

void printTree(BinaryTreesNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    cout << root->data << " :";
    if(root->left != NULL)
    {
        cout << " L" << root->left->data;
    }

    if(root->right != NULL)
    {
        cout << " R" << root->right->data;
    }

    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}

BinaryTreesNode<int>* takeInput()
{
    int rootData;
    cout <<"Enter data : ";
    cin>>rootData;

    if(rootData==(-1))
    {
        return NULL;
    }

    BinaryTreesNode<int>* left = takeInput();
    BinaryTreesNode<int>* right = takeInput();

    BinaryTreesNode<int>* root = new BinaryTreesNode<int>(rootData);

    left->parent = root;
    right->parent = root;
    root->left = left;
    root->right = right;

    return root;
}

BinaryTreesNode<int>* takeInputLevelWise()
{
    int rootData;
    cout << "Enter the rootdata : ";
    cin>>rootData;

    if(rootData==(-1))
    {
        return NULL;
    }

    BinaryTreesNode<int>* root = new BinaryTreesNode<int>(rootData);

    queue<BinaryTreesNode<int>*> nodes;

    nodes.push(root);

    while(!nodes.empty())
    {
        BinaryTreesNode<int>* front = nodes.front();

        int left;
        cout << "Enter the left data of "<< front->data <<" : ";
        cin>>left;

        if(left!=(-1))
        {
            BinaryTreesNode<int>* leftNode = new BinaryTreesNode<int>(left);

            front->left = leftNode;

            nodes.push(leftNode);
        }

        int right;
        cout << "Enter the right data of "<< front->data <<" : ";
        cin>>right;

        if(right!=(-1))
        {
            BinaryTreesNode<int>* rightNode = new BinaryTreesNode<int>(right);

            front->right = rightNode;

            nodes.push(rightNode);
        }

        nodes.pop();
    }

    return root;
}

void printBinaryTreeLevelWise(BinaryTreesNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<BinaryTreesNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        BinaryTreesNode<int>* front = pendingNodes.front();

        cout << front->data << " :";

        if(front->left)
        {
            pendingNodes.push(front->left);
            cout << " L" << front->left->data;
        }

        if(front->right)
        {
            pendingNodes.push(front->right);
            cout << " R"<< front->right->data;
        }

        cout<<endl;

        pendingNodes.pop();
    }
}

int numberOfNodes (BinaryTreesNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int ans = 0;

    if(root->left)
    {
        ans += numberOfNodes(root->left);
    }

    if(root->right)
    {
        ans += numberOfNodes(root->right);
    }

    return (ans+1);
}

void mirrorTree(BinaryTreesNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    BinaryTreesNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void printLevelATNewLine(BinaryTreesNode<int> *root) {
    queue<BinaryTreesNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreesNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int height(BinaryTreesNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

int diameterOfTree(BinaryTreesNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int heightOfTree = 1 + height(root->left) + height(root->right);
    // int heightOfTree = height(root);
    int leftDiameter = diameterOfTree(root->left);
    int rightDiameter = diameterOfTree(root->right);

    return max(heightOfTree,max(leftDiameter,rightDiameter));
}

pair<int, int> heightDiameter(BinaryTreesNode<int>* root)
{
    if(root==NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;

        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int rh = rightAns.first;

    int ld = leftAns.second;
    int rd = rightAns.second;

    pair<int, int> p;
    p.first = 1 + max(lh,rh);
    p.second = max(lh+rh,max(ld,rd));

    return p;
}

// bool isBST(BinaryTreesNode<int> *root) {
// 	// Write your code here
//     if(root==NULL)
//     {
//         return true;
//     }
    
//     bool check = false;
    
//     if((root->left!=NULL) && ((root->data)<=(root->left->data)))
//     {
//         check = false;
//         return check;
//     }
    
//     else if((root->right!=NULL) && ((root->data)>=(root->right->data)))
//     {
//         check = false;
//         return check;
//     }
    
//     else
//     {
//         bool left = isBST(root->left);
//         bool right = isBST(root->right);
        
//         if(left && right)
//         {
//             check = true;
//         }
        
//         else
//         {
//             check = false;
//         }
//     }
    
//     return check;
// }

int minimum(BinaryTreesNode<int>* root)
{
    static int minima = INT_MAX;
    if(root==NULL)
    {
        return INT_MAX;
    }
    
    minima = min(root->data, min(minimum(root->left), minimum(root->left)));
    
    return minima;
}

int maximum(BinaryTreesNode<int>* root)
{
    static int maxima = INT_MIN;
    if(root==NULL)
    {
        return INT_MIN;
    }
    
    maxima = max(root->data, max(maximum(root->left), maximum(root->right)));
    
    return maxima;
}

bool isBST(BinaryTreesNode<int> *root) 
{
    if(root==NULL)
    {
        return true;
    }
    
    int maxOfLeft = maximum(root->left);
    int minOfRight = minimum(root->right);
    
	bool check = (maxOfLeft < root->data) && (minOfRight >= root->data) && isBST(root->left) && isBST(root->right);
    
    return check;
}

isBSTReturn isBST2(BinaryTreesNode<int>* root)
{
    if(root==NULL)
    {
        isBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;

        return output;
    }

    isBSTReturn left = isBST2(root->left);
    isBSTReturn right = isBST2(root->right);

    isBSTReturn ans;

    ans.isBST = (left.maximum < root->data) && (right.minimum > root->data) && left.isBST && right.isBST;

    ans.maximum = max(root->data,max(left.maximum,right.maximum));
    ans.minimum = min(root->data,min(left.minimum,right.minimum));

    return ans;
}

bool isBST3(BinaryTreesNode<int>* root,int min = INT_MIN,int max = INT_MAX)
{
    if(root==NULL)
    {
        return true;
    }

    if(((root->data) < min) || ((root->data) > max))
    {
        return false;
    }

    bool left = isBST3(root->left,min,root->data-1);
    bool right = isBST3(root->right,root->data,max);

    return (left && right);
}

vector<int>* getRootToNodePath(BinaryTreesNode<int>* root,int k)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==k)
    {
        vector<int>* ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }

    vector<int>* leftOutput = getRootToNodePath(root->left,k);
    if(leftOutput!=NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right,k);
    if(rightOutput!=NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }

    else
    {
        return NULL;
    }
}