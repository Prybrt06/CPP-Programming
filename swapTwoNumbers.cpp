#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int b = 20;

    cout<<a<<" "<<b<<endl;
    
    int term;
    term = a;
    a = b ; 
    b = term;

    cout<<a<<" "<<b<<endl;
}