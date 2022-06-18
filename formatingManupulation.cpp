#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a = 32;                         
    int b = 129243;         
    cout<<setw(5);
    cout<<setfill('*');
    cout<<a<<"\n"<<b<<"\n";                       /* ***32
                                                   129243 */

    cout<<left;
    cout<<setw(5);
    cout<<setfill('*');
    cout<<a<<"\n"<<b<<endl;                       /*   32***
                                                       129243    */

}