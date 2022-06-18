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
        while(j<=a-i)
        {
            cout<<"  ";
            j++;
        }

        int k=1;
        while(k<=i)
        {
            cout<<k<<" ";
            k++;
        }

        int l=1;
        while(l<=i-1)
        {
            cout<<i-l<<" ";
            l++;
        }

        cout<<endl;
        i++;
    }
}