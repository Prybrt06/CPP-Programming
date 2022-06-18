#include<stdio.h>
#include<math.h>

int main()
{
    int i=0;
    // double two = 2;
    // double eighty = 80;
    double rem;

    while(i<=1)
    {
        rem = pow(2,80)%91;
    }

    printf("The remainder is %d",rem);

    return 0;
}