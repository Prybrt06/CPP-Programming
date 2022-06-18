#include<iostream>
using namespace std;

class stack
{
    int *data;
    int current;
    int capacity;

    public:
    stack(int size)
    {
        data = new int[size];
        current = 0;
        capacity = size;
    }

    void push(int a)
    {   
        if(current==capacity)
        {
            cout<<"Stack is already full\n";
        }
        else
        {
            data[current] = a;
            current++;
        }
    }

    void pop()
    {
        current--;
    }

    int top()
    {
        return data[current-1];
    }

    bool isempty()
    {
        if(current==0)
        {
            return true;
        }

        return false;
    }

    int size()
    {
        return current;
    }

};

int main()
{
    stack nw = stack(5);

    nw.push(10);
    nw.push(20);
    nw.push(30);
    nw.push(40);
    nw.push(50);
    nw.push(60);

    cout<<nw.top()<<endl;

    nw.pop();
    nw.pop();
    nw.pop();
    nw.pop();
    nw.pop();
    nw.pop();

    cout<<nw.top()<<endl;

    cout<<nw.isempty()<<endl;
}