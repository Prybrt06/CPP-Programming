#include<iostream>
#include<math.h>
using namespace std;

int subsequences(string input,string output[])
{
    if(input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallstring = input.substr(1);
    int small_ans = subsequences(smallstring,output);

    for(int i=0;i<small_ans;i++)
    {
        output[i+small_ans] = input[0] + output[i];
    }

    return 2*small_ans;
}

int main()
{
    string str;
    cin>>str;

    int size = str.size();

    int size_of_subsequences = pow(2,size);

    string* output = new string[size_of_subsequences];
    int count = subsequences(str,output);

    for(int i=0;i<count;i++)
    {
        cout<<output[i]<<endl;
    }
}