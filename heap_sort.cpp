#include<iostream>
using namespace std;

void heapSort(int *arr,int n)
{
    int i=1;
    int parentIndex = (i-1)/2;

    while(i<n)
    {
        int j = i;
        while(arr[j]<arr[parentIndex])
        {
            int temp = arr[j];
            arr[j] = arr[parentIndex];
            arr[parentIndex] = temp;

            j = parentIndex;
            parentIndex = (j-1)/2;
        }

        i++;
        parentIndex = (i-1)/2;
    }

    while(n)
    {
        int temp = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = temp;

        int parentIndex = 0;
        int leftChildIndex = (2*parentIndex)+1;
        int rightChildIndex = (2*parentIndex)+2;

        n--;

        while(leftChildIndex<n)
        {
            int minIndex = parentIndex;
            if(arr[minIndex]>arr[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }

            if((rightChildIndex<n) && (arr[minIndex]>arr[rightChildIndex]))
            {
                minIndex = rightChildIndex;
            }

            if(minIndex==parentIndex)
            {
                break;
            }

            int temp = arr[parentIndex];
            arr[parentIndex] = arr[minIndex];
            arr[minIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2*parentIndex) + 1;
            rightChildIndex = (2*parentIndex) + 2;
        }
    }
}

int main()
{
    int arr[8] = {5,8,3,1,6,2,7,9};

    heapSort(arr,8);

    for(int i:arr)
    {
        cout << i <<" ";
    }
}