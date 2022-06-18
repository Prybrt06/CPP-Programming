#include<iostream>
using namespace std;

int index(int *arr,int n,int k)
{
    int start = 0;
    int end = n-1;

    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==k)
        {
            return mid;
        }

        else if(arr[mid]<k)
        {
            start = mid + 1;
        }

        else if(arr[mid]>k)
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    cout<<index(arr,n,k)<<endl;
}