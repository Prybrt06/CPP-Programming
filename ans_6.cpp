#include<iostream>
using namespace std;

int main()
{
    int a;
    cout<<"Give the number\n";
    cin>>a;

    bool check = true;

    if(a==1)
    {
        check = false;
    }

    else
    {
        for(int i=2;i<a;i++)
        {
            if(a%i==0)
            {
                check = false;
                break;
            }
        }
    }

    if(check)
    {
        cout<<"The number is a prime number\n";
    }

    else
    {
        cout<<"The number is not a prime number\n";
    }

    return 0;
}