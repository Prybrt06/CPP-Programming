#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    int i=1;
    char ch = 'A';

    while(i<=a)
    {
        int j=1;
        while(j<=i)
        {
            cout<<ch<<" ";
            ch++;
            j++;
        }

        cout<<endl;
        i++;
    }
}