#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Deque
{
    int size;
    Node *head;
    Node *tail;
    int capacity;

public :

    Deque(int length)
    {
        size = 0;
        head = NULL;
        tail = NULL;
        capacity = length;
    }

    void insertFront(int val)
    {
        if(size>=capacity)
        {
            cout<<"-1"<<endl;
            return;
        }

        Node *newNode = new Node(val);
        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }

        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertRear(int val)
    {
        if(size>=capacity)
        {
            cout<<"-1"<<endl;
            return;
        }

        Node *newNode = new Node(val);
        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void deleteFront()
    {
        if(head==NULL)
        {
            cout<<"-1"<<endl;
            return;
        }

        if(size==1)
        {
            Node *a = head;
            head = NULL;
            tail = NULL;
            size--;
            delete a;
            return;
        }

        Node *a = head;
        head = head->next;

        size--;

        delete a;
    }

    void deleteRear()
    {
        if(head==NULL)
        {
            cout<<"-1"<<endl;
            return;
        }

        if(size==1)
        {
            Node *a = head;
            head = NULL;
            tail = NULL;
            size--;
            delete a;
            return;
        }

        Node *temp = head;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }

        Node *a = tail;
        temp->next = NULL;
        tail = temp;
        size--;
        delete a;
    }

    int getFront()
    {
        if(head==NULL)
        {
            return -1;
        }

        return head->data;
    }

    int getRear()
    {
        if(head==NULL)
        {
            return -1;
        }

        return tail->data;
    }
};