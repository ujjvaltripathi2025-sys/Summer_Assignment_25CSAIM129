#include<stdio.h>
int main()
{
    int n,rem,bin=0,place=1,temp;
    printf("Enter the Decimal Number:");
    scanf("%d",&n);
    temp=n;

    while(n>0)
    {
        rem=n%2;
        bin=bin+rem*place;
        place=place*10;
        n=n/2;
    }
    printf("Binary of %d is= %d\n",temp,bin);
    return 0;

}