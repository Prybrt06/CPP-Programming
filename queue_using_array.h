#include<iostream>
using namespace std;

template <typename T>
class queue
{
    T *data;
    int size;
    int nextIndex;
    int firstIndex;
    int capacity;

public:

    queue (int size_of_array)
    {
        data = new T[size_of_array];
        size = 0;
        nextIndex = 0;
        firstIndex = 0;
        capacity = size_of_array;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return getSize()==0;
    }

    void enqueue(T element)
    {
        if(nextIndex==capacity)
        {
            cout<<"Queue will overflow\n";
            return;
        }

        data[nextIndex] = element;
        nextIndex++;
        size++;
    }

    T dequeue()
    {
        if(isEmpty())
        {
            return -1;
        }
        T ans = data[0];
        for(int i=1;i<nextIndex;i++)
        {
            data[i-1] = data[i];
        }

        size--;
        nextIndex--;
        return ans;
    }

    T front()
    {
        if(isEmpty())
        {
            return -1;
        }

        return data[0];
    }
};