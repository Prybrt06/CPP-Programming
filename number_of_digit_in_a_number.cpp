#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    int ans=0;

    while (a!=0)
    {
        ans++;
        a /=10;
    }

    cout<<ans<<endl;
    
}