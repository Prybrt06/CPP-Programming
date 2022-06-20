#include <iostream>
using namespace std;
#include<queue>

void findMedian(int *arr, int n)
{
    priority_queue<int, vector<int>, greater<int> > min;
    priority_queue<int> max;
    
    for(int i=0;i<n;i++)
    {
        
        
        if(max.empty() && min.empty())
        {
            max.push(arr[i]);
        }
        
        else if(arr[i]>max.top())
        {
            min.push(arr[i]);
        }

        else
        {
            max.push(arr[i]);
        }
        
        if(max.size()>min.size())
        {
            if((max.size()-min.size())>1)
            {
                min.push(max.top());
                max.pop();
                arr[i] = (min.top() + max.top())/2;
            }
            
            else
            {
                arr[i] = max.top();
            }
        }
        
        else if(min.size()>max.size())
        {
            if((min.size()-max.size())>1)
            {
                max.push(min.top());
                min.pop();
                arr[i] = (min.top() + max.top())/2;
            }
            
            else
            {
                arr[i] = min.top();
            }
        }
        
        
        else
        {
            arr[i] = (min.top() + max.top())/2;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}