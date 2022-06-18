#include<iostream>
#include<array>
using namespace std;

int max(int a,int b,int c)
{
    if((a>b) && (a>c))
    {
        return a;
    }

    else if((b>a) && (b>c))
    {
        return b;
    }

    else
    {
        return c;
    }
}


int main()
{
    int n;
    int arr[n];

    cin>>n;

    int ans[n-2];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n-2;i++)
    {
        ans[i] = max(arr[i],arr[i+1],arr[i+2]);
    }

    for(int i=0;i<n-2;i++)
    {
        cout<<ans[i]<<" ";
    }
}
