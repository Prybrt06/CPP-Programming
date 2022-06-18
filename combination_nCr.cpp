#include<iostream>
using namespace std;

int factorial(int a)
{
    if(a==1)
    {
        return a;
    }

    return a*factorial(a-1);
}

int value_of_nCr(int n, int r)
{
    int factorial_of_n = factorial(n);
    int factorial_of_r = factorial(r);
    int factorial_of_n_minus_r = factorial(n-r);

    int ans = factorial_of_n/(factorial_of_r*factorial_of_n_minus_r);

    return ans;
}

int main()
{
    int n , r ;
    cout<<"Input the value of n : ";
    cin>>n;

    cout<<"Input the value of r : ";
    cin>>r;

    cout<<"The ans of the nCr is : "<<value_of_nCr(n,r)<<endl;
}