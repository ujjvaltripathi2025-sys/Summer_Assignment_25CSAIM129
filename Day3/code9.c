#include<stdio.h>
int main()
{
    int n,prime=1,i;
    printf("Enter the Number Greater than 1:");
    scanf("%d",&n);

    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            prime=0;
            break;
        }
    }
    if(prime==1)
    {
        printf("%d is Prime",n);
    }
    else
    {
        printf("%d is not Prime",n);
    }
    return 0;
}