#include <iostream>
#include <string>
#define ll long long int
#define ull unsigned long long int
using namespace std;

ll M = 998244353;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll a[n];

    if (s[0] == '1')
    {
        a[0] = 1;
    }

    ll prev = a[0];

    for (ll i = 1; i < n; i++)
    {
        if (s[i] == '1')
        {
            prev += (i + 1);
        }
        
        a[i] = prev;
        a[i] = a[i] % 2;
    }

    ll p = 1;
    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (a[i] == 1)
        {
            ans += p;
            ans = ans % M;
        }
        p = p * 2;
        p = p % M;
    }
    cout << ans % M << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}