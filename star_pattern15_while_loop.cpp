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
        while(j<=i-1)
        {
            cout<<"  ";
            j++;
        }

        int k=1;
        while(k<=(a-i+1))
        {
            cout<<"* " ;
            k++;
        }

        cout<<endl;
        i++;
    }
}
