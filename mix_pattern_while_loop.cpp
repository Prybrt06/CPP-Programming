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
        while(j<=a-i+1)
        {
            cout<<j<<" ";
            j++;
        }

        int k=1;
        while(k<=(2*i)-2)
        {
            cout<<"* ";
            k++;
        }

        int l=1;
        while(l<=a-i+1)
        {
            cout<<a-l+1<<" ";
            l++;
        }

        cout<<endl;
        i++;
    }
}
