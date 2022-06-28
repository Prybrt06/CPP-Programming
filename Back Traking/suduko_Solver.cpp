#include<iostream>
using namespace std;

#define N 9

bool findEmptyPosition(int arr[N][N],int &row,int &column)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(arr[i][j]==0)
            {
                row = i;
                column = j;
                return true;
            }
        }
    }

    return false;
}

bool isSafeForRow(int arr[N][N],int row,int val)
{
    for(int i=0;i<N;i++)
    {
        if (arr[row][i]==val)
        {
            return false;
        }
    }

    return true;
}

bool isSafeForColumn(int arr[N][N],int column,int val)
{
    for(int i=0;i<N;i++)
    {
        if (arr[i][column]==val)
        {
            return false;
        }
    }

    return true;
}

bool isSafeFor3x3Matrix(int arr[N][N],int row,int column,int val)
{
    int rowStart = row - row%3;
    int columnStart = column - column%3;

    int rowEnd = rowStart + 2;
    int columnEnd = columnStart + 2;
    
    for(int i=rowStart;i<=rowEnd;i++)
    {
        for(int j=columnStart;j<=columnEnd;j++)
        {
            if(arr[i][j] == val)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int arr[N][N],int row,int column,int val)
{
    bool a = isSafeForRow(arr,row,val);
    bool b = isSafeForColumn(arr,column,val);
    bool c = isSafeFor3x3Matrix(arr,row,column,val);

    return (a && b && c);
}

bool sudukoSolver(int arr[N][N])
{
    int row,column;
    if(!findEmptyPosition(arr,row,column))
    {
        return true;
    }

    for(int i=1;i<=N;i++)
    {
        if(isSafe(arr,row,column,i))
        {
            arr[row][column] = i;
            if(sudukoSolver(arr))
            {
                return true;
            }

            arr[row][column] = 0;
        }
    }

    return false;
}

int main()
{
    int arr[9][9];

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>arr[i][j];
        }
    }

    bool check =  sudukoSolver(arr);

    if(check)
    {
        cout << "true";
    }
    
    else
    {
        cout << "false";
    }

    // for(int i=0;i<9;i++)
    // {
    //     delete [] arr[i];
    // }

    // delete [] arr;
}

/*

3 0 6 5 0 8 4 0 0 
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

*/