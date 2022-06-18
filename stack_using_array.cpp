#include<iostream>
using namespace std;

class stack
{
    int *data;
    int nextIndex;
    int capacity;

public:

    stack (int size_of_the_array)
    {
        data = new int[size_of_the_array];
        nextIndex = 0;
        capacity = size_of_the_array;
    }

    void push(int a)
    {
        if(nextIndex==capacity)
        {
            cout<<"The stack will overflow\n";
            return;
        }
        data[nextIndex] = a;
        nextIndex++;
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
        if(nextIndex==0)
        {
            cout<<"Empty"<<endl;
            return -1;
        }

        return data[nextIndex-1];
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        if(nextIndex==0)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    stack s(5);

    s.push(5);

    cout<<s.size()<<endl;
    cout<<s.top()<<endl;

    s.push(6);

    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;

    s.pop();
    s.pop();

    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;
}
