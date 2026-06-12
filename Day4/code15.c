#include<stdio.h>
int main()
{
    int n,sum=0,d,temp;
    printf("Enter the Number:");
    scanf("%d",&n);
    temp=n;

    while(n>0)
    {
        d=n%10;
        sum=sum+(d*d*d);
        n=n/10;
    }
    if(sum==temp)
    {
        printf("Number is Armstrong");
    }
    else
    {
        printf("Number is not Armstrong");
    }
    return 0;
}