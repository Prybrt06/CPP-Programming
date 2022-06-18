#include<iostream>
using namespace std;

int main()
{
    int number;
    cin>>number;
    bool res = (number%2) & (1);
    
    if(res == 1)
    {
        cout<<"You\n";
    }
    
    else if(res == 0)
    {
        cout<<"Friend\n";
    }
}
