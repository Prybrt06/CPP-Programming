#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main()
{

    // char ch[4] = {12,160,50,8};

    // int asci[4] = {12,160,50,8};

    // int ans[4];

    // int e = 47;
    // int n = 187;

    // float d = 1/47.0;

    // for(int i=0;i<4;i++)
    // {
    //     float a = pow(asci[i],d);

    //     ans[i] = a;
    // }

    // char ch_ans[4];

    // for(int i=0;i<4;i++)
    // {
    //     int a = 64+ans[i];

    //     char ch = a;

    //     ch_ans[i] = ch;
    // }

    // cout << ch_ans <<endl;

    int a=3,b,c;
    b = --a + ++a + a++ - a--;
    c = a++ + a++ - --a + b-- + --b;

    cout << a << " " << b << " " << c;
}