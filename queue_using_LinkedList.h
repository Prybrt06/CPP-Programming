#include<iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

int size_of_ll(Node *head)
{
    Node *temp = head;
    int count = 0;

    while(temp!=NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

class queue
{
    Node *head;
    Node *tail;
    int size;

public:

    queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return getSize()==0;
    }

    void enqueue(int element)
    {
        Node *newNode = new Node(element);
        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }

        tail->next = newNode;
        tail = tail->next;
        size++;
    }

    int dequeue()
    {
        if(isEmpty())
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

    int front()
    {
        if(isEmpty())
        {
            return -1;
        }

        return head->data;
    }
};