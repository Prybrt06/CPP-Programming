#include<iostream>
#include<climits>
using namespace std;

void selection_sort(int *arr,int n)
{
    int i=1;
    int min = INT_MAX;
    int index;
    while(i<n)
    {
        for(int j=i-1;j<n;j++)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                index = j;
            }
        }

        int temp = arr[i-1];
        arr[i-1] = arr[index];
        arr[index] = temp;

        i++;
        min = INT_MAX;
    }
}

void insertionSort(int *arr, int n)
{
    int i = 1;
    while(i<=n-1)
    {
        for(int j=i-2;j>=0;j--)
        {
            if(arr[j+1]<arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        i++;
    }
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

    // selection_sort(arr,n);

    insertionSort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}