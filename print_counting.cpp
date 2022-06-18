#include<iostream>
using namespace std;

void print_counting(int a)
{
    for(int i=1;i<=a;i++)
    {
        cout<<i<<" ";
    }
}

int main()
{
    int a;
    cin>>a;

    print_counting(a);
}