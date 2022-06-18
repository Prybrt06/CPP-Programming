#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int main()
{
    Node* head = new Node(3);
    Node* a = new Node(4);

    head->next = a;

    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}