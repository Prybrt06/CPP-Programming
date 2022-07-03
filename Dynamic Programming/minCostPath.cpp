#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;

int getMinCost_DynamicProgramming(int **input,int m,int n)
{
    int **output = new int*[m];

    for(int i=0;i<m;i++)
    {
        output[i] = new int[n];
    }

    output[m-1][n-1] = input[m-1][n-1];

    for(int i=m-2;i>=0;i--)
    {
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }

    for(int j=n-2;j>=0;j--)
    {
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }

    for(int i=m-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            int x = output[i+1][j];
            int y = output[i+1][j+1];
            int z = output[i][j+1];

            output[i][j] = min(x,min(y,z)) + input[i][j];
        }
    }

    return output[0][0];
}

int getMinCost_Memorization(int **input,int m,int n,int row,int column)
{
    if((row == m-1) && (column == n-1))
    {
        return input[row][column];
    }

    if(row >= m || column >= n)
    {
        return INT_MAX;
    }

    unordered_map<int,int> map;

    if(map.count(input[row][column])>0)
    {
        return map[input[row][column]];
    }

    int x = getMinCost_Memorization(input,m,n,row+1,column);
    int y = getMinCost_Memorization(input,m,n,row+1,column+1);
    int z = getMinCost_Memorization(input,m,n,row,column+1);

    map[input[row][column]] = min(x,min(y,z)) + input[row][column];

    return map[input[row][column]];
}

int getMinCost_BruteForce(int **input,int m,int n,int row,int column)
{
    if((row == m-1) && (column == n-1))
    {
        return input[row][column];
    }

    if(row >= m || column >= n)
    {
        return INT_MAX;
    }

    int x = getMinCost_BruteForce(input,m,n,row+1,column);
    int y = getMinCost_BruteForce(input,m,n,row+1,column+1);
    int z = getMinCost_BruteForce(input,m,n,row,column+1);

    return min(x,min(y,z)) + input[row][column];
}

int getMinCost(int **input,int m,int n)
{
    // return getMinCost_BruteForce(input,m,n,0,0);
    // return getMinCost_Memorization(input,m,n,0,0);
    return getMinCost_DynamicProgramming(input,m,n);
}

int main()
{
    int m,n;
    cin>>m>>n;

    int **arr = new int*[m];

    for(int i=0;i<m;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    cout << getMinCost(arr,m,n) << endl;

    return 0;
}