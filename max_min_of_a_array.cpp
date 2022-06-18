#include<iostream>
using namespace std;

void array_input(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
}

void max_num(int arr[],int size)
{
    int ans = INT_MIN ;

    for(int i=0;i<size;i++)
    {
        if(arr[i]>ans)
        {
            ans = arr[i];
        }
    }

    cout<<ans<<endl;
}

void min_num(int arr[],int size)
{
    int ans = INT_MAX ;

    for(int i=0;i<size;i++)
    {
        if(arr[i]<ans)
        {
            ans = arr[i];
        }
    }

    cout<<ans<<endl;
}

int main()
{
    int a;
    cin>>a;

    int arr[a];

    array_input(arr,a);

    cout<<"The largest value in the array is : ";
    max_num(arr,a);

    cout<<"The smallest value in the array is : ";
    min_num(arr,a);
}