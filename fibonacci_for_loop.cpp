#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    int num1 = 0;
    int num2 = 1;
    int num3;

    for(int i=1;i<=a;i++)
    {
        cout<<num1<<" ";
        num3 = num1 + num2;
        int term = num2;
        num2 = num3;
        num1 = term;
    }
}