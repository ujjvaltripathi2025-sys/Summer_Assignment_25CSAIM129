#include<stdio.h>
int main()
{
    int n,d,Rev=0;
    printf("Enter the Number:");
    scanf("%d",&n);

    while(n>0)
    {
        d=n%10;
        Rev=Rev*10+d;
        n=n/10;
    }
    printf("The Reverse is=%d",Rev);
    return 0;
}