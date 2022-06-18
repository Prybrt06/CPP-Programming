#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    char ch[a+1];

    cin>>ch;

    for(int start=0,end=a-1;start<=end;start += 2,end -= 2)
    {
        char temp = ch[start];
        ch[start] = ch[end];
        ch[end] = temp;
    }

    cout<<ch;

}
