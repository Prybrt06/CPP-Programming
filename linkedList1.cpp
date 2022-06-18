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

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* take_input()
{
    int val;
    cin>>val;
    char ch = 'y';
    
    Node* head = NULL;
    while(ch=='y')
    {
        Node* newnode = new Node(val);
        if(head==NULL)
        {
            head = newnode;
        }

        else
        {
            Node* temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        cout<<"Do you like to add more number\n";
        cin>>ch;
        cin>>val;
    }
    return head;
}

Node* take_input_better()
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

Node* insert_at_key(Node* head,int i,int val)
{
    Node* newnode = new Node(val);
    int count = 0;
    Node* temp = head;
    if(i==0)
    {
        newnode->next = temp;
        head = newnode;
        return head;
    }

    while(count<i-1)
    {
        temp = temp->next;
        count++;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

Node* delete_at_key(Node* head,int i)
{
    Node* temp = head;
    if(i==0)
    {
        head = head->next;
        return head;
    }

    int count = 0;
    while(count<i-1)
    {
        temp = temp->next;
        count++;
    }

    temp->next = temp->next->next;

    return head;
}

int main()
{
    Node* head = take_input_better();
    print(head);

    int key,val;
    cin>>key>>val;
    head = insert_at_key(head,key,val);
    print(head);

    int key2;
    cin>>key2;
    head = delete_at_key(head,key2);
    print(head);
}