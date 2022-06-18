#include<iostream>
using namespace std;

int main()
{
    int a;
    cout<<"Input the Number\n";
    cin>>a;

    int check = 0;

    for(int i=a+1;i<=a+100;i++)
    {
        for(int j=2;j<i;j++)
        {
            check = 0;
            if(i%j==0)
            {
                check++;
                break;
            }
        }

        if(check==0)
        {
            cout<<i<<endl;
            return 0;
            break;
        }
    }
}