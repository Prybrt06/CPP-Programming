#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    int ans = 1;

    for(int i=a;i>=1;i--)
    {
        ans *= i;
    }

    cout<<ans<<endl;
}