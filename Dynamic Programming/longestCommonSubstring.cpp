#include<iostream>
#include<string.h>
using namespace std;

int lcs_DynamicProgramming(string s1,string s2)
{
    int m = s1.length();
    int n = s2.length();

    int **output = new int*[m+1];

    for(int i=0;i<=m;i++)
    {
        output[i] = new int[m+1];
    }

    for(int j=0;j<=n;j++)
    {
        output[0][j] = 0;
    }

    for(int i=0;i<=m;i++)
    {
        output[i][0] = 0;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[m-i] == s2[n-j])
            {

                output[i][j] = output[i-1][j-1] + 1;
                continue;

            }

            int a = output[i][j-1];
            int b = output[i-1][j];
            int c = output[i-1][j-1];

            output[i][j] = max(a,max(b,c));
        }
    }

    return output[m][n];
}

int lcs_memorization(string s1,string s2,int **output, int m,int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }

    if(output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;

    if(s1[0]==s2[0])
    {
        ans = 1 + lcs_memorization(s1.substr(1),s2.substr(1),output,m-1,n-1);
    }

    else
    {
        int a = lcs_memorization(s1.substr(1),s2,output,m-1,n);
        int b = lcs_memorization(s1,s2.substr(1),output,m,n-1);

        ans = max(a,b);
    }

    output[m][n] = ans;

    return ans;
}

int lcs_memorization(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    int **output = new int*[m+1];

    for(int i=0;i<=m;i++)
    {
        output[i] = new int[n+1];
        for(int j=0;j<=n;j++)
        {
            output[i][j] = -1;
        }
    }

    return lcs_memorization(s1,s2,output,m,n);
}

int lcs(string s1,string s2)
{
    if(s1.length()==0 || s2.length()==0)
    {
        return 0;
    }

    if(s1[0]==s2[0])
    {
        return 1 + lcs(s1.substr(1),s2.substr(1));
    }

    else
    {
        int a = lcs(s1.substr(1),s2);
        int b = lcs(s1,s2.substr(1));
        int c = lcs(s1.substr(1),s2.substr(1));

        return max(a,max(b,c));
    }
}

int main()
{
    string s1,s2;

    cin>>s1>>s2;

    cout << lcs_DynamicProgramming(s1,s2) << endl;
}