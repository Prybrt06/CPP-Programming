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
        while(j<=(a-i))
        {
            cout<<"  ";
            j++;
        }

        int k=1;
        while(k<=i)
        {
            cout<<"* ";
            k++;
        }

        cout<<endl;
        i++;
    }
}