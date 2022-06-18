#include<iostream>
using namespace std;

int DigitalRoot(int a)
{
    if(a<10)
    {
        return a;
    }

    int lastDigit;
    int ans = 0;

    while(a>0)
    {
        lastDigit = a%10;
        ans += lastDigit;
        a /= 10;
    }

    return DigitalRoot(ans);
}

int main()
{
    int n;
    cin>>n;

    cout<<DigitalRoot(n);
}