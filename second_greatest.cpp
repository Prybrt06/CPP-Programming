#include<iostream>
using namespace std;
#include <climits>


int main(){
    int a;
    cin>>a;
    
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    
    if(a==1)
    {
        cout<<max1;
    }

    else
    {
        int arr[a];
        
        for(int i=0;i<a;i++)
        {
            cin>>arr[i];
        }
        
        for(int i=0;i<a;i++)
        {
            if(arr[i]>max1)
            {
                max1 = arr[i];
            }
        }

        for(int i=0;i<a;i++)
        {
            if(arr[i]==max1)
            {
                arr[i] = INT_MIN;
                break;
            }
        }

        for(int i=0;i<a;i++)
        {
            if(arr[i]>max2)
            {
                max2 = arr[i];
            }
        }
        
        if(max1 == max2)
        {
            cout<<INT_MIN;
        }
        else
        {
            cout<<max2;
        }
    }
    
    return 0;
}

