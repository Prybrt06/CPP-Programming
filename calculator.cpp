#include<iostream>
using namespace std;

int main()
{
    int a,b ;
    cout<<" Input the numbers\n";
    cin>>a>>b ;
    char operation ;
    cout<<" Input the operation\n";
    cin>>operation ;

    switch(operation)
    {
        case '+' :
            cout << (a+b) << endl ;
            break ;

        case '*' :
            cout << (a*b) << endl ;
            break ;

        case '-' :
            cout << (a-b) << endl ;
            break ;

        case '/' :
            cout << (a/b) << endl ;
            break ;

        default :
            cout << "Operation not valid\n" ;
            break ;
    }
}