#include<iostream>
using namespace std;

void take_input(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
}

bool search(int arr[],int size, int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int size;
    cout<<"Input the size of the array : ";
    cin>>size;

    int arr[size];

    cout<<"Input the inputs in the array : ";
    take_input(arr,size);

    int key;
    cout<<"Input the number that you want to check : ";
    cin>>key;

    if(search(arr,size,key))
    {
        cout<<"The number you want to check is in the array :-) \n";
    }

    else
    {
        cout<<"The number you want to check is not in the array :-( \n";
    }
}