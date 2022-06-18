#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cout<<i*j<<" ";
        }
        cout<<endl;
    }
}