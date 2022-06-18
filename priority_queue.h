#include<iostream>
#include<vector>
// #include "binary_trees.h"
using namespace std;


/*
     *********** This is a min priority queue *************
*/


class priorityQueue
{
    vector<int> v;
    int nextIndex;

  public:
    priorityQueue()
    {
        nextIndex = 0;
    }


    pair<int,int> parentData_index(int index)
    {
        int parentIndex = (index-1)/2;

        pair<int,int> p;
        p.first = v.at(parentIndex);
        p.second = parentIndex;

        return p;
    }

    void checkChild(int index)
    {
        if(((2*index)+1)>(v.size()-1))
        {
            cout<<"No child"<<endl;
            return;
        }

        cout<<v.at((2*index)+1)<<" ";

        if(((2*index)+2)<=(v.size()-1))
        {
            cout<<v.at((2*index)+2);
        }

        cout<<endl;
    }

    void deleteElement()
    {
        nextIndex--;
    }

    bool isEmpty()
    {
        return v.empty();
    }

    int getSize()
    {
        return v.size();
    }

    int getMin()
    {
        if(isEmpty())
        {
            cout << "The queue is empty\n";
            return INT_MIN;
        }

        return v[0];
    }

    void insert(int data)
    {
        v.push_back(data);
        int childIndex = nextIndex;
        int parentIndex = parentData_index(childIndex).second;

        while(v.at(parentIndex)>v.at(childIndex) && childIndex!=0)
        {
            int temp = v.at(parentIndex);
            v.at(parentIndex) = v.at(childIndex);
            v.at(childIndex) = temp;

            childIndex = parentIndex;
            parentIndex = parentData_index(childIndex).second;
        }

        nextIndex++;
    }

    int removeMin() {
        if(v.size()==0)
        {
            return INT_MIN;
        }
        
        int ans = v[0];
        v[0] = v[v.size()-1];
        v.pop_back();
        
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        
        while(leftChildIndex<v.size())
        {
            int maxIndex = parentIndex;
            if(v[maxIndex]>v[leftChildIndex])
            {
                maxIndex = leftChildIndex;
            }
            if(rightChildIndex<v.size() && v[maxIndex]>v[rightChildIndex])
            {
                maxIndex = rightChildIndex;
            }
            
            if(maxIndex==parentIndex)
            {
                break;
            }
            
            int temp = v[maxIndex];
            v[maxIndex] = v[parentIndex];
            v[parentIndex] = temp;
            
            parentIndex = maxIndex;
            leftChildIndex = 2*parentIndex + 1;
        	rightChildIndex = 2*parentIndex + 2;
        }
        
        return ans;
    }
};