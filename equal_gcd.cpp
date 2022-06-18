//Name : Priyabrat Duarah
//Scholar id : 2111137

#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;
#define ll long long int

ll g_c_d(ll a, ll b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return g_c_d(a-b, b);
    return g_c_d(a, b-a);
}

int main()
{
    ll a;
    cin>>a;

    ll arr[a];

    for(ll i=0;i<a;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+a);

    ll count = 0;
    bool check =  true;

    for(ll i=0;i<=arr[0];i++)
    {
        for(ll j=1;j<a;j++)
        {
            ll gcd = g_c_d(i,arr[j]);
            if(gcd!=i)
            {
                check = false;
                break;
            }
        }

        if(check)
        {
            count++;
        }

        check = true;
    }    

    cout<<count;
}