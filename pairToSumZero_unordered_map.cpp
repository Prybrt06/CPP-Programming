#include <iostream>
using namespace std;
#include<unordered_map>

int decSum(int a)
{
    if(a==0)
    {
        return 0;
    }
    
    return a + decSum(a-1);
}

int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> map;
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
        map[arr[i]]++;
        if(arr[i]==0)
        {
            continue;
        }
        
        if(map.count((-1)*(arr[i]))>0)
        {
            ans += map[(-1)*(arr[i])];
        }
    }
    
    if(map.count(0)>0)
    {
        if(map[0]!=0)
        {
            ans += decSum(map[0]-1);
        }
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
