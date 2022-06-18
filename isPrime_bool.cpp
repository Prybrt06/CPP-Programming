#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    bool isPrime = true;

    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
            isPrime = false;
            break;
        }
    }

    if(isPrime)
    {
        cout<<"The number is a prime number\n";
    }

    else
    {
        cout<<"The number is not a prime number\n";
    }
}