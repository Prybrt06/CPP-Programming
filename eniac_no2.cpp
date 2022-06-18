//Name : Priyabrat Duarah
//Scholar id : 2111137

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    stack<int> st; 
    int count = 1;
    while(n--)
    {
        int a;
        cin>>a;
        int lastDigit;
        int size = 0;
        while(a!=0)
        {
            lastDigit = a%10;

            if(lastDigit!=1 && lastDigit!=3)
            {
                break;
            }
            size++;

            a /= 10;
        }

        if(a==0 && size<=k)
        {
            cout<<count<<endl;
        }

        count++;
    }

}