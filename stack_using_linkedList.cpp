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

int size_of_LL(Node *head)
{
    Node *temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

/*
class Stack {
	// Define the data members
    Node *val;
   public:
    Stack() {
        val = new Node(-1);
        // Implement the Constructor
    }

    int getSize() {
        Node *temp = val;
        int count = 0;
        
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        
        return count-1;
        // Implement the getSize() function
    }

    bool isEmpty() {
        if(val->next==NULL )
        {
            return true;
        }
        
        return false;
        // Implement the isEmpty() function
    }

    void push(int element) {
        
        Node *temp = val;
        
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        
        Node *newNode = new Node(element);
        
        temp->next = newNode;
        // Implement the push() function
    }

    int pop() {
        
        if(isEmpty())
        {
            return -1;
        }
        
        Node *temp = val;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        
        Node *a = temp->next;
        temp->next = NULL;
        
        int b = a->data;
        
        delete a;
        
        return b;
        // Implement the pop() function
    }

    int top() {
        
        if(isEmpty())
        {
            return -1;
        }
        
        Node *temp = val;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        
        return temp->data;
        // Implement the top() function
    }
};
*/

/*
class Stack
{
    Node *head;
    Node *tail;

public:

    Stack()
    {
        head = NULL;
        tail = NULL;
    }

    int getSize()
    {
        return size_of_LL(head);
    }

    bool isEmpty()
    {
        return getSize==0;
    }

    void push(int element)
    {
        Node *newNode = new Node(element);
        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        else
        {
            tail->next = newNode;
            tail = tail->next; 
            return;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            return -1;
        }

        Node *temp = head;

        while(temp->next!=tail)
        {
            temp = temp->next;
        }

        Node *a = temp->next;
        tail = temp;

        int ans = a->data;
        delete a;
        return ans;
    }

    int top()
    {
        if(isEmpty())
        {
            return -1;
        }

        return tail->data;
    }
};
*/

class Stack
{
    Node *head;
    int size;

public:

    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (getSize()==0);
    }

    void push(int element)
    {
        size++; 

        Node *newNode = new Node(element); 

        newNode->next = head;
        head = newNode;
    }

    int pop()
    {
        if(head==NULL)
        {
            return -1;
        }

        Node *a = head;
        int ans = a->data;
        
        head = head->next;
        delete a;
        size--;
        return ans;
    }

    int top()
    {
        if(head==NULL)
        {
            return -1;
        }

        return head->data;
    }
};