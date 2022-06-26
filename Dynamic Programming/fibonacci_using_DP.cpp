#include<iostream>
using namespace std;

int nFibonacci(int n)
{
    int *arr = new int[n+1];
    
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2;i<=n;i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
  
    return arr[n];
}

int main()
{
    int n;
    cin>>n;

    cout << nFibonacci(n) << endl;
  
    return 0;
}
