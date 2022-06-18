#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int input[m][n];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
        }
    }

    int count = 0 ;
    int totalElements = m*n ;
    
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = m - 1;
    int endingCol = n - 1;

    
}