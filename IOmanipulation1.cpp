#include<iostream>
using namespace std;

int main()
{
    bool a = true;
    cout<<a<<"\n";                         //1
    cout<<boolalpha;                       
    cout<<a<<"\n";                         //true
    cout<<noboolalpha;
    cout<<a<<"\n";                         //1
}