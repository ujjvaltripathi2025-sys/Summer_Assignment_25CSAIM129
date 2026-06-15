#include<stdio.h>
int main()
{
    int n,i,max_prime=-1;
    printf("Enter a Positive Integer:");
    scanf("%d",&n);

    while(n%2==0)
    {
        max_prime=2;
        n=n/2;
    }
    for(i=3;i<=n;i++)
    {
        while(n%i==0)
        {
            max_prime=i;
            n=n/i;
        }
    }
    if(n>2)
    {
        max_prime=n;
    }
    if(max_prime!=-1)
    {
        printf("The Largest Prime Factor is=%d",max_prime);
    }
    else
    {
        printf("No Prime Factors Found");
    }
    return 0;
}