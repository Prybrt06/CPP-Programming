#include<iostream>
using namespace std;

int reverse_integer(int a)
{
    int lastDigit ;
    int sum = 0 ;

    while(a!=0)
    {
        lastDigit = a%10 ;
        sum = sum*10 + lastDigit ;
        a /= 10 ;
    }

    return sum ;
}

int main()
{
    int a;
    cin>>a;

    cout<<reverse_integer(a)<<endl;
}