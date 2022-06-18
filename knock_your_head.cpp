#include<iostream>
using namespace std;

int main()
{
    int count = 0;
    for(int i=100;i<=999;i++)
    {
        if(i%8==4)
        {
            count++;
        }
    }

    cout<<count<<endl;
}