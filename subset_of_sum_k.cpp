#include <iostream>
using namespace std;
//#include "solution.h"

void printSubsetSumToK(int input[], int size, int k) 
{
    // Write your code here
    if(size==0)
    {
        cout<<""<<endl;
        return;
    }

    if(input[0]<k)
    {
        for(int i=1;i<size;i++)
        {
            if(input[0]+input[i]==k)
            {
                cout<<input[0]<<" "<<input[i];
            }
            cout<<endl;
        }
    }
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}