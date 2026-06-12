#include<stdio.h>
int main()
{
    int n,d,Sum=0;
    printf("Enter the Number:");
    scanf("%d",&n);

    while(n>0)
    {
        d=n%10;
        Sum=Sum+d;
        n=n/10;
    
    }
    printf("The Sum of Digits is=%d",Sum);
    return 0;
}