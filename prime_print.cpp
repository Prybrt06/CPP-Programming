#include<iostream>
using namespace std;

void printPrime(int a)
{
    for(int i=2;i<=a;i++)
    {
        int ans;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                break;
            }
            ans = j;
        }

        if(ans==(i-1))
        {
            cout<<i<<" ";
        }
    }

    return;
}

int main()
{
    int a;
    cin>>a;

    printPrime(a);
}
