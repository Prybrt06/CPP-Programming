#include<iostream>
#include<climits>
using namespace std;

class stack
{
    int *data;
    int nextIndex;
    int capacity;

public :

    stack()
    {
        capacity = 5;
        data = new int[capacity];
        nextIndex = 0;
    }

    void inc_size_of_array()
    {
        capacity *= 2;

        int *newdata = new int[capacity];

        for(int i=0;i<(capacity/2);i++)
        {
            newdata[i] = data[i];
        }

        delete []data;
        data = newdata;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex==0;
    }

    void push(int a)
    {
        if(nextIndex==capacity)
        {
            inc_size_of_array();
        }

        data[nextIndex] = a;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Empty\n";
            return;
        }

        nextIndex--;
    }

    int top()
    {
        if(isEmpty())
        {
            return INT_MIN;
        }

        return data[nextIndex-1];
    }
};

int main()
{
    stack s;

    s.push(6);
    s.push(6);
    s.push(6);
    s.push(6);
    s.push(6);
    s.push(6);
    s.push(6);

    
}