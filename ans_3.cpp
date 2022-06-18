#include<iostream>
using namespace std;

int main()
{
    bool check = true;

    for(int i=1;i<=100;i++)
    {
        if(i==1)
        {
            continue;
        }

        else if(i==2)
        {
            cout<<i<<" ";
            continue;
        }

        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                check = false;
                break;
            }
        }

        if(check)
        {
            cout<<i<<" ";
        }

        check = true;
    }

    return 0;
}