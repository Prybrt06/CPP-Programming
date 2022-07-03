#include<iostream>
#include<string.h>
using namespace std;

int editDistance_dynamicProgramming(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    
    int **output = new int*[m+1];
    
    for(int i=0;i<=m;i++)
    {
        output[i] = new int[n+1];
    }
    
    output[0][0] = 0;
    
    for(int j=1;j<=n;j++)
    {
        output[0][j] = j;
    }
    
    for(int i=1;i<=m;i++)
    {
        output[i][0] = i;
    }
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[m-i] == s2[n-j])
            {
                output[i][j] = output[i-1][j-1];
            }
            
            else
            {
                int a = output[i][j-1];
                int b = output[i-1][j-1];
                int c = output[i-1][j];
                
                output[i][j] = 1 + min(a,min(b,c));
            }
        }
    }
    
    int ans = output[m][n];
    
    for(int i=0;i<=m;i++)
    {
        delete [] output[i];
    }
    
    delete [] output;
    
    return ans;
}

int editDistance_memorization(string s1, string s2, int **output)
{
    int m = s1.length();
    int n = s2.length();
    
    if(m==0 || n==0)
    {
        return max(m,n);
    }
    
    if(output[m][n] != -1)
    {
        return output[m][n];
    }
    
    int ans;
    
    if(s1[0] == s2[0])
    {
        ans = editDistance_memorization(s1.substr(1),s2.substr(1),output);
    }
    
    else
    {
        int x = 1 + editDistance_memorization(s1.substr(1),s2,output);
        int y = 1 + editDistance_memorization(s1,s2.substr(1),output);
        int z = 1 + editDistance_memorization(s1.substr(1),s2.substr(1),output);
        
        ans = min(x,min(y,z));
    }
    
    output[m][n] = ans;
    
    return ans;
}

int editDistance_memorization(string s1, string s2)
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
    
    int ans = editDistance_memorization(s1,s2,output);
    
    for(int i=0;i<=m;i++)
    {
        delete [] output[i];
    }
    
    delete [] output;
    
    return ans;
}

int editDistance(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    
    if(m==0 || n==0)
    {
        return max(m,n);
    }
    
    int ans;
    
    if(s1[0] == s2[0])
    {
        return editDistance_memorization(s1.substr(1),s2.substr(1));
    }
    
    else
    {
        int x = 1 + editDistance_memorization(s1.substr(1),s2);
        int y = 1 + editDistance_memorization(s1,s2.substr(1));
        int z = 1 + editDistance_memorization(s1.substr(1),s2.substr(1));
        
        return min(x,min(y,z));
    }
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    cout << editDistance(s1,s2) << endl;
    cout << editDistance_memorization(s1,s2) << endl;
    cout << editDistance_dynamicProgramming(s1,s2) << endl;

    return 0;
}