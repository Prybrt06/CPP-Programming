#include<iostream>
using namespace std;

void isPrime(int a)
{
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
            cout<<"The number is not a prime number\n";
            return;
        }
    }

    cout<<"The number is a prime number\n";
    return;
}

int main()
{
    int a;
    cin>>a;

    isPrime(a);
}