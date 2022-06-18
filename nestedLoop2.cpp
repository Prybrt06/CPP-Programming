#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=a;j++)
        {
            cout<<j*i<<" "; 
        }
        cout<<endl;
    }
}