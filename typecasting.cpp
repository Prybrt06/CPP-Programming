#include<iostream>
#include "this.h"
using namespace std;

int main(){
    float a = 45.46;
    cout<<a<<endl;
    cout<<int(a)<<endl;
    cout<<(int)a<<endl;

    int b = int(a);
    cout<<b<<endl;

    cout<< (a + a)<<endl<<(a + int(a))<<endl;
    return 0;
}