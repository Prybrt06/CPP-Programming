#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class customer
{
    char type;
    int diposit_amount;
    int balance;
    float amount_after_loan;
    int check_loan;

public:
    customer()
    {
        cout<<"Who is the customer? lenders or borrowers !! For lender type 'L' and for borrowers type 'B' \n";
        cin>>type;
        if(type=='B')
        {
            check_loan = 0;
        }
        balance = 0;
    }

    void diposit(int a)
    {
        if(type=='B')
        {
            cout<<"Invalid Activity\n";
            return;
        }

        balance += a;
    }

    int balance()
    {
        if(type=='B')
        {
            cout<<"Invalid Activity\n";
            return -1;
        }

        return balance;
    }

    void loan(int ammount,int year)
    {
        if(type=='L')
        {
            cout<<"Invalid Activity\n";
        }

        if(check_loan!=0)
        {
            cout<<"You have already taken a loan! \n So you are not eligible for a another loan :-( \n";
            return;
        }

        if(ammount>1000000)
        {
            cout<<"We provide loan upto 10 lakhs only. Thank you :-)\n";
            return;
        }

        int asset;
        float total_payable_ammount;
        cout<<"The value of total asset you have : ";
        cin>>asset;

        int extra_year;
        int penalty;

        if(asset>=ammount)
        {
            if(ammount>0 && ammount<=100000)
            {
                if(year>3)
                {
                    extra_year = year - 3;
                    penalty = 10000*extra_year;
                }

                else
                {
                    penalty = 0;
                }
            }

            else if(ammount>100000 && ammount<=200000)
            {
                if(year>5)
                {
                    extra_year = year - 5;
                    penalty = 10000*extra_year;
                }

                else
                {
                    penalty = 0;
                }
            }

            else if(ammount>200000 && ammount<=300000)
            {
                if(year>7)
                {
                    extra_year = year - 7;
                    penalty = 20000*extra_year;
                }

                else
                {
                    penalty = 0;
                }
            }

            else if(ammount>300000 && ammount<=500000)
            {
                if(year>9)
                {
                    extra_year = year - 9;
                    penalty = 20000*extra_year;
                }

                else
                {
                    penalty = 0;
                }
            }

            else if(ammount>500000 && ammount<=1000000)
            {
                if(year>10)
                {
                    extra_year = year - 10;
                    penalty = 30000*extra_year;
                }

                else
                {
                    penalty = 0;
                }
            }

            total_payable_ammount = penalty + (1.0)*ammount*pow((1+(9.0/100)),year);

            string confirmation;
            cout<<"You should pay "<<total_payable_ammount<<" after "<<year<<"year(s)\n";
            cout<<"Shall We Continue? yes or no \n";
            cin>>confirmation;

            if(confirmation=="yes")
            {
                check_loan++;
                amount_after_loan = total_payable_ammount;
                cout<<"Congratulatios you get the loan !! \n";
                return;
            }

            else
            {
                cout<<"OOPS!! See you again \n";
                return;
            }

        }

        else
        {
            cout<<"You are not eligible for the loan\n";
            return;
        }
    }

    int amount_including_interesting()
    {
        if(check_loan==0)
        {
            cout<<"You didn't take any loan !! \n";
            return;
        }

        return amount_after_loan;
    }
};
