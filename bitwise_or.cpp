#include<iostream>
using namespace std;

int main()
{
    int a;cin>>a;

    int ans = 1;

    for(int i=2;i<=a;i++)
    {
        ans = ans|i;

        cout<<i<<" : "<<ans<<endl;
    }

    //cout<<(16|1)<<endl;
}