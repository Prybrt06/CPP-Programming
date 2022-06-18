#include<iostream>
using namespace std;

void take_input(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
}

void print_output(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void reverse_array(int arr[],int size)
{
    int ans[size];

    for(int i=0,j=size-1; i<size,j>=0;i++,j--)
    {
        ans[j] = arr[i];
    }

    print_output(ans,size);
}

int main()
{
    int size;
    cin>>size;

    int arr[size];

    take_input(arr,size);

    print_output(arr,size);

    reverse_array(arr,size);
}