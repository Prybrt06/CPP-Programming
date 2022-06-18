#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;
    int check = 0;
    
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
            cout<<"The number is not a prime number\n";
            check++;
            break;
        }
    }

    if(check==0)
    {
        cout<<"The number is a prime number\n";
    }
}