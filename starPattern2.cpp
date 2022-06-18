#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    for(int i=1;i<=a;i++)
    {
        for(int j=a-i;j>=1;j--)
        {
            cout<<" ";
        }

        int n = (2*i) - 1;
        for(int j=1;j<=n;j++)
        {
            cout<<"*";
        }

        for(int j=a-i;j>=1;j--)
        {
            cout<<" ";
        }

        cout<<endl;
    }
}