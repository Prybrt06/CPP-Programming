#include<iostream>
using namespace std;

int main()
{
    int a;
    cout<<"Enter a number in Binary form\n";
    cin>>a;

    int ans = 0;
    int lastDigit;
    int multiplier = 1;

    while(a>0)
    {
        lastDigit = a%10;
        ans += (lastDigit*multiplier);
        multiplier *= 2;
        a /= 10;
    }

    cout<<ans<<endl;
}