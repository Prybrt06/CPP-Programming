#include<iostream>
#include<math.h>
using namespace std ;

int reverse(int a)
{
    int lastDigit ;
    int sum = 0 ;

    while( a != 0 )
    {
        lastDigit = a%10 ;
        sum = ( sum * 10 ) + lastDigit ;
        a /= 10 ;
    }

    return sum ;
}

int decimal_to_binary(int a)
{
    int rem ;
    int ans = 0 ;

    while(a!=0)
    {
        int n = a / 2 ;
        rem = a - ( 2 * n ) ;

        ans = ( ans * 10 ) + rem ;
        a /= 2 ;
    }

    ans = reverse(ans) ;

    return ans ;
}

int main()
{

    int a ;
    cin >> a ;
    
    cout << decimal_to_binary(a) << endl ;

}
