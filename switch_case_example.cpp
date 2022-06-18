#include<iostream>
using namespace std;

int main()
{
    int a;
    cout<<"Enter the amount\n";
    cin>>a;

    switch (1)
    {
        case 1 : 
            int hundred;
            hundred = a/100 ;
            a = a - (hundred*100) ;
            cout<<"Numbers of Hundred rupees notes are : "<<hundred<<endl;
        
        case 2 :
            int fifty;
            fifty = a/50 ;
            a = a - (fifty*50) ;
            cout<<"Numbers of Fifty rupees notes are : "<<fifty<<endl;

        case 3 :
            int twenty;
            twenty = a/20 ;
            a = a - (twenty*20) ;
            cout<<"Numbers of Twenty rupees notes are : "<<twenty<<endl;

        case 4 :
            int one;
            one = a/1 ;
            a = a - (one*1) ;
            cout<<"Numbers of one rupee coins are : "<<one<<endl;

        default : 
            break;
    }
}