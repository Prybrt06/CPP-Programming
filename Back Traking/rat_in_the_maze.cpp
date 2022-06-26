#include<iostream>
using namespace std;

void printSolution(int **visited,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << visited[i][j] << " ";
        }
    }

    cout << endl;
}

void mazeHelp(int **arr,int **visited,int n,int row,int column)
{
    
    if(row==n-1 && column==n-1)
    {
        visited[row][column] = 1;
        printSolution(visited,n);
        visited[row][column] = 0;

        return;
    }

    if(row==n || row<0 || column==n || column<0 || arr[row][column]==0 || visited[row][column]==1)
    {
        return;
    }

    visited[row][column] = 1;
    mazeHelp(arr,visited,n,row+1,column);
    mazeHelp(arr,visited,n,row,column+1);
    mazeHelp(arr,visited,n,row-1,column);
    mazeHelp(arr,visited,n,row,column-1);
    visited[row][column] = 0;
}

void solveRatInMaze(int **arr,int n)
{
    int **visited = new int*[n];
    
    for(int i=0;i<n;i++)
    {
        visited[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            visited[i][j] = 0;
        }
    }

    mazeHelp(arr,visited,n,0,0);

    for(int i=0;i<n;i++)
    {
        delete [] visited[i];
    }

    delete [] visited;
}

int main()
{
    int n;
    cin>>n;

    int **arr = new int*[n];

    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    solveRatInMaze(arr,n);

    for(int i=0;i<n;i++)
    {
        delete [] arr[i];
    }

    delete [] arr;

    return 0;
}
