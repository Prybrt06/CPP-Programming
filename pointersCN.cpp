#include<iostream>
using namespace std;

void inc_five(int &a)
{
    a += 5;
}

int main()
{
    int i = 5;
    int &j = i;
    inc_five(j);

    cout<<i<<endl;
}