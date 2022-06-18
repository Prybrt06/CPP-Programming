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
    int start = 0 ;
    int end = size - 1 ;

    while(end>=start)
    {
        swap(arr[end],arr[start]);
        end--;
        start++;
    }
}

int main()
{
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;

    int arr[size];

    cout<<"Enter the elements in the array : ";
    take_input(arr,size);

    cout<<"The original array is : ";
    print_output(arr,size);

    reverse_array(arr,size);

    cout<<"The reversed array is : ";
    print_output(arr,size);
}