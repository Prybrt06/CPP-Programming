#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    int i=1;

    char start = 65;

    while(i<=a)
    {
        int j=1;

        while(j<=a)
        {
            cout<<start<<" ";
            j++;
        }

        start++;
        i++;
        cout<<endl;
    }
}