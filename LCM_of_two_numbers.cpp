#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    int max_limit = a*b;

    int ans;

    for(int i=1;i<=max_limit;i++)
    {
        if(i%a==0 && i%b==0)
        {
            ans = i;
            break;
        }
    }

    cout<<ans<<endl;
}