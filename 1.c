// #include<stdio.h>

// int main()
// {
//     int a,ans = 0,remainder,i=1;
//     scanf("%d",&a);

//     while(a!=0)
//     {
//         remainder = a%5;
//         a /= 5;
//         ans += (remainder*i);
//         i *= 10;
//     }

//     printf("%d",ans);

//     return 0;
// }

#include <stdio.h>

int main() {

    int a=3,b,c;
    b = (--a) + (++a) + (a++) - (a--);
    c = (a++) + (a++) - (--a) + (b--) + (--b);
    
    printf("A=%d\tB=%d\tC=%d\t",a,b,c);


    return 0;
}

// int func(int num)
// {
//     if(num>20)
//     {
//         return 100;
//     }  

//     else 
//     {
//         return 200;
//     }
// }

// int f(int i)
// {
//     return (i%2);
// }

// int funct(int a)
// {
//     printf("Hello");
//     goto A;
// }



