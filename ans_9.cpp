#include<iostream>
using namespace std;

int main()
{
    int a;
    cout<<"Enter the number\n";
    cin>>a;

    int lastdigit;
    int ans = 0;

    while(a!=0)
    {
        lastdigit = a%10;
        ans = ans*10 + lastdigit;
        a /= 10;
    }

    cout<<ans<<endl;
}