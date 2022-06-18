#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    while(a--)
    {
        float P,l;
        cout<<"P : ";
        cin>>P;
        cout<<"l : ";
        cin>>l;

        float ans = (2*50*l)/(P*100);

        cout<<"The answer is : "<<ans<<endl;
    }
}
