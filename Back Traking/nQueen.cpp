#include<iostream>
using namespace std;

int board[11][11];

bool isPossible(int n,int row,int column)
{
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][column])
        {
            return false;
        }
    }

    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }

    for(int i=row-1,j=column+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j])
        {
            return false;
        }
    }

    return true;
}

void helper(int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << board[i][j] << " "; 
            }
        }

        cout << endl;
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(isPossible(n,row,j))
        {
            board[row][j] = 1;
            helper(n,row+1);
            board[row][j] = 0;
        }
    }
}

void solveNQueen(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j] = 0;
        }
    }

    helper(n, 0);
}

int main()
{
    int n;
    cin>>n;

    solveNQueen(n);

    return 0;
}
