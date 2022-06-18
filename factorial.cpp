#include<iostream>
using namespace std;

//template <typename T>
int factorial(int a)
{
    if(a==1)
    {
        return 1;
    }

    return a*factorial(a-1);
}

int main()
{
    int p;
    cin>>p;

    int ans = factorial(p);

    cout<<ans<<"\n";
}