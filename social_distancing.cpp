//Name : Priyabrat Duarah
//Scholar id : 2111137

#include<iostream>
using namespace std;

#define ll long long int

int main()
{
    ll a;
    cin>>a;
    
    ll arr[a];

    for(ll i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    
    ll ans = 0;
    
    for(ll i=0;i<a;i++)
    {
        ans += arr[i];
    }
    
    cout<<ans;
    
    return 0;
}