#include<stdio.h>
int main()
{
    int n,Decimal=0,base=1,rem,temp;
    printf("Enter a Binary Number:");
    scanf("%d",&n);
    temp=n;

    while(n>0)
    {
        rem=n%10;
        Decimal=Decimal+rem*base;
        base=base*2;
        n=n/10;
    }
    printf("Decimal of %d is=%d\n",temp,Decimal);
    return 0;
}