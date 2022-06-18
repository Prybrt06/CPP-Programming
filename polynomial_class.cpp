#include<iostream>
using namespace std;

class Polynomial 
{
    public:
    
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    
    Polynomial()
    {
        capacity = 5;
        degCoeff = new int[capacity];
            
        for(int i=0;i<capacity;i++)
        {
            degCoeff[i] = 0;
        }
    }
    
    int getCap(Polynomial const &p)
    {
        return capacity;
    }
    
    Polynomial(Polynomial const &p)
    {
        this -> capacity = p.capacity;
        this -> degCoeff = new int[capacity];
        
        for(int i=0;i<capacity;i++)
        {
            this -> degCoeff[i] = p.degCoeff[i];
        }
    }
    
    int max(Polynomial const &p)
    {
        if(capacity >= p.capacity)
        {
            return capacity;
        }
        
        else
        {
            return p.capacity;
        }
    }
    
    void inc_cap()
    {
        capacity *= 2;
        int *newdeg = new int[capacity];
            
        for(int i=0;i<(capacity/2);i++)
        {
            newdeg[i] = degCoeff[i];
        }
            
        for(int i=(capacity/2);i<capacity;i++)
        {
            newdeg[i] = 0;
        }
        
        degCoeff = newdeg;
    }
    
    Polynomial operator= (Polynomial const &p)
    {
        this -> capacity = p.capacity;
        this -> degCoeff = new int[capacity];
        
        for(int i=0;i<capacity;i++)
        {
            this -> degCoeff[i] = p.degCoeff[i];
        }
    }
    
    void setCoefficient(int degree, int coeff)
    {
        if(degree<capacity)
        {
            degCoeff[degree] = coeff;
            return;
        }
        
        else
        {
            capacity *= 2;
            int *newdeg = new int[capacity];
            
            for(int i=0;i<(capacity/2);i++)
            {
                newdeg[i] = degCoeff[i];
            }
            
            for(int i=(capacity/2);i<capacity;i++)
            {
                newdeg[i] = 0;
            }
            
            degCoeff = newdeg;
            
            setCoefficient(degree,coeff);
        }
    }
    
    
    
    Polynomial operator+ (Polynomial p)
    {
        Polynomial ans;
        
        int max_deg = max(p);
        
        if(max_deg<=ans.capacity)
        {
            for(int i=0;i<capacity;i++)
            {
                ans.degCoeff[i] = this->degCoeff[i] + p.degCoeff[i];
            }
        }
        
        else
        {
            ans.inc_cap();
            for(int i=0;i<capacity;i++)
            {
                ans.degCoeff[i] = this->degCoeff[i] + p.degCoeff[i];
            }
        }
        
        return ans;
    }
    
    Polynomial operator- (Polynomial p)
    {
        Polynomial ans;
        
        int max_deg = max(p);
        
        if(max_deg<=ans.capacity)
        {
            for(int i=0;i<capacity;i++)
            {
                ans.degCoeff[i] = this->degCoeff[i] - p.degCoeff[i];
            }
        }
        
        else
        {
            ans.inc_cap();
            for(int i=0;i<capacity;i++)
            {
                ans.degCoeff[i] = this->degCoeff[i] - p.degCoeff[i];
            }
        }
        
        return ans;
    }
    
    Polynomial operator* (Polynomial p)
    {
        Polynomial ans;
        
        int max_deg = max(p);
        
        if(max_deg<=ans.capacity)
        {
            for(int i=0;i<capacity;i++)
            {
                for(int j=0;j<p.capacity;j++)
                {
                    ans.degCoeff[i+j] = degCoeff[i] * p.degCoeff[i];
                }
            }
        }
        
        else
        {
            ans.inc_cap();
            
            for(int i=0;i<capacity;i++)
            {
                for(int j=0;j<p.capacity;j++)
                {
                    ans.degCoeff[i+j] = degCoeff[i] * p.degCoeff[i];
                }
            }
        }
        
        return ans;
    }
    
    void print()
    {
        for(int i=0;i<capacity;i++)
        {
            if(degCoeff[i]==0)
            {
                continue;
            }
            
            cout<<degCoeff[i]<<"x"<<i<<" ";
        }
    }
    // Complete the class
    
};


int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}


