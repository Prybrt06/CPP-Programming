#include<iostream>
using namespace std;

void subs_str(string input,string output)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }

    subs_str(input.substr(1),output);
    subs_str(input.substr(1),output + input[0]);
}

int main()
{
    string str;
    cin>>str;

    subs_str(str,"");
}