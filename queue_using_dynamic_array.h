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
        firstIndex = -1;
        capacity = size_of_array;
    }

    void inc_sizeof_array()
    {
        capacity *= 2;
        T *newData = new T[capacity];
        for(int i=0;i<(capacity/2);i++)
        {
            newData[i] = data[i];
        }

        delete []data;
        data = newData;
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
        if(firstIndex==-1)
        {
            firstIndex = 0;
        }

        else if(nextIndex==capacity)
        {
            inc_sizeof_array();
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