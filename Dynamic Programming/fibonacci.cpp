#include<iostream>
#include<unordered_map>
using namespace std;

int helper(int n,unordered_map<int,int> map)
{
    if(n<=1)
    {
        return n;
    }

    if(map.count(n)>0)
    {
        return map[n];
    }

    else
    {
        int a = helper(n-1,map);
        int b = helper(n-2,map);

        map[n] = a+b;
    }

    return map[n];
}

int nFibonacci(int n)
{
    unordered_map<int,int> map;

    return helper(n,map);
}

int main()
{
    int n;
    cin>>n;

    cout << nFibonacci(n) << endl;
}
