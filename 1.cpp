#include<iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    
    if(n == 0 && num == 1){
        cout << "Neither Prime nor Composite";
        return 0;
    }
    
    int i = 2;
    while(i < num){
        if(n % i == 0){
            cout << "No";
            return 0;
        }
        i++;
    }
    cout << "Yes";
    return 0;
}
