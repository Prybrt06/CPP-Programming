#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    int min;

    if(a>b)
    {
        min = b;
    }

    else
    {
        min = a;
    }

    cout<<min<<endl;

    int ans;

    for(int i=1;i<=min;i++)
    {
        if(a%i==0 && b%i==0)
        {
            ans = i;
        }
    }

    cout<<ans<<endl;
}