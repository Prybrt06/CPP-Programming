#include<iostream>
using namespace std;

int main()
{
    int arr1[] = {1,3,4,6};
    int arr2[] = {1,2,5,9,10};

    int ans[9];

    int a = 0;
    int b = 0;

    for(int i=0;i<9;i++)
    {
        if(a>=4)
        {
            ans[i] = arr2[b];
            b++;
            continue;
        }

        else if(b>=5)
        {
            ans[i] = arr1[a];
            a++;
            continue;
        }

        if(arr1[a]>arr2[b])
        {
            ans[i] = arr2[b];
            b++;
        }

        else
        {
            ans[i] = arr1[a];
            a++;
        }
    }

    for(int i=0;i<9;i++)
    {
        cout<<ans[i]<<" ";
    }
}