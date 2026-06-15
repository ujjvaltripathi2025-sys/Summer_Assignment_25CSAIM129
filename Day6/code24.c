#include<stdio.h>
int main()
{
    int x,n,i;
    long long power=1;

    printf("Enter the Base Value x :");
    scanf("%d",&x);
    printf("Enter Exponent Value n :");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        power=power*x;
    }
    printf("The Value of %d^%d is = %lld\n",x,n,power);
    return 0;
}