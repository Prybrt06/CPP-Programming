#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    int i=1;
    while(i<=a)
    {
        int j=1;
        while(j<=i)
        {
            char start = 'A' + j - 1;
            cout<<start<<" ";
            j++;
        }

        int k=1;
        while(k<=i-1)
        {
            char end = 'A' + i - k - 1;
            cout<<end<<" ";
            k++;
        }

        cout<<endl;
        i++;
    }
}