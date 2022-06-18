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

Node* take_input()
{
    int data;
    cin>>data;

    Node *head = NULL;
    while(data!=-1)
    {
        Node *n = new Node(data);
        if(head==NULL)
        {
            head = n;
        }
        
        else
        {
            Node *temp = head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
        }

        cin>>data;
    }
}

void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data>>" ";
        head=head->next;
    }
}

int main()
{
    Node *head = take_input();
    print(head);
}