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

        while (j<=a)
        {
            cout<<i<<" ";
            j++;
        }
        
        cout<<endl;
        i++;
    }
}