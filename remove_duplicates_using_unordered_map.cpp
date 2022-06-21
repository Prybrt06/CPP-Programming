#include<iostream>
#include<unordered_map>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
    unordered_map<char, int> myMap;
    string s;
    getline(cin,s);

    cout<<s<<endl;

    vector<char> v;

    int j = 0;
    for(int i=0;i<s.length();i++)
    {
        myMap[s[i]]++;

        if(myMap[s[i]]<=1)
        {
            v.push_back(s[i]);
            j++;
        }
    }

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
}
