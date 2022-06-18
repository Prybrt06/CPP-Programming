#include<iostream>
using namespace std;

int main()
{
    int number;
    cin>>number;
    if(number<10)
    {
        cout<<"Small";
    }
    
    else if(number>100)
    {
        cout<<"Big";
    }
    
    else
    {
        cout<<"Number";
    }
}