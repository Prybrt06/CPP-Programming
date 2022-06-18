#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    float arr[19];

    // cout<<tan(45*3.14159/180);

    for(int i=0;i<19;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<19;i++)
    {
        float rad = (arr[i]*3.14159)/180;

        cout<<tan(rad)<<endl;
    }
}