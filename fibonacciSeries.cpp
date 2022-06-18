#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int ans = 0;

    int a=1,b=1;
    int c;

    for(int i=1;i<=n;i++)
    {
        c = a+b;
        cout<<a<<" ";
        a = b;
        b = c;
    }
}