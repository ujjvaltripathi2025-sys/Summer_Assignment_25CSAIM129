#include <stdio.h>
int sum(int);
int main()
{
    int n;
    printf("Enter the Number:");
    scanf("%d",&n);

    printf("Sum of Digits is = %d\n",sum(n));
    return 0;
}
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return (n%10+sum(n/10));
    }
}