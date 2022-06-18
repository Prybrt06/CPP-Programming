#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* take_input()
{
    int val;
    cin>>val;

    Node* head = NULL;
    Node* tail = NULL;

    while(val!=-1)
    {
        Node* newnode = new Node(val);

        if(head==NULL)
        {
            head = newnode;
            tail = newnode;
        }

        else
        {
            tail->next = newnode;
            tail = tail->next;
        }

        cin>>val;
    }

    return head;
}

void print(Node* head)
{
    Node *temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

Node* insert_at_key(Node *head,int i,int val)
{
    Node* heead = head;
    Node* newnode = new Node(val);
    Node* temp = heead;
    int count = 0;

    if(i==0)
    {
        newnode->next = heead;
        heead = newnode;
        return heead;
    }

    

    else
    { 
        while(count<i-1)
        {
            temp=temp->next;
            count++;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    return heead;
}

Node* delete_at_key(Node* head,int i)
{
    int count = 0 ;
    Node* temp = head;

    if(i==0)
    {
        head = head->next;
        delete temp;
        return head;
    }

    else
    {
        while(count<i-1)
        {
            temp = temp->next;
            count++;
        }

        //delete temp->next;
        temp->next = temp->next->next;
        
    }

    return head;
}

Node* deletion_by_val (Node* head,int val)
{
    Node* temp = head;
    if(val==(temp->data))
    {
        temp = temp->next;
        head = temp;
        return head;
    }

    while(temp->next->data!=val)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;

    return head;
}
