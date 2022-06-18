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
    if(size%2==0)
    {
        for(int i=0;i<(size/2);i++)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

    else
    {
        for(int i=0;i<((size/2)+1);i++)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
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