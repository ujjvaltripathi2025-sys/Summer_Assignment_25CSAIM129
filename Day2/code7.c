#include<stdio.h>
int main()
{
    int n,d,Product=1;
    printf("Enter a Number:");
    scanf("%d",&n);

    while(n>0)
    {
        d=n%10;
        Product=Product*d;
        n=n/10;
    }
    printf("Product of Digits is=%d",Product);
    return 0;
}