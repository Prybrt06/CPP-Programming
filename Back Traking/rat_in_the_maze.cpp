#include<iostream>
using namespace std;

bool isPossible(int **arr,bool **visit,int n,int row,int column)
{
    if(row<n)
    {
        if(arr[row][column]==1)
        {
            if(visit[row][column]==false)
            {
                return true;
            }
        }
    }

    if(column<n)
    {
        if(arr[row][column]==1)
        {
            if(visit[row][column]==false)
            {
                return true;
            }
        }
    }
    

    return false;
}

void helper(int n,int arr,int row,int column)
{
    
}

void solveRatInMaze(int n,int **arr)
{
    bool **visit = new bool*[n];

    for(int i=0;i<n;i++)
    {
        visit[i] = new bool[n];
        for(int j=0;j<n;j++)
        {
            visit[i][j] = false;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i+1)!=n)
            {
                if(isPossible(arr,visit,n,i+1,j))
                {
                    visit[i+1][j] = true;
                    solveRatInMaze(n,arr);
                }
            }
            
        }
    }
}

int main()
{
    int a;
    cin>>a;

    int **arr = new int*[a];

    for(int i=0;i<a;i++)
    {
        arr[i] = new int[a];
        for(int j=0;j<a;j++)
        {
            cin>>arr[i][j];
        }
    }

    solveRatInMaze(a,arr);

    for(int i=0;i<a;i++)
    {
        delete [] arr[i];
    }

    delete [] arr;
}
