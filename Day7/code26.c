#include<stdio.h>
int fib(int);
int main()
{
    int n,i;
    printf("Enter Number of Terms:");
    scanf("%d",&n);

    printf("Fibonacci Series:");
    for(i=0;i<=n-1;i++)
    {
        printf("%d\n",fib(i));
    }
    printf("\n");
    return 0;
}
int fib(int i)
{
    if(i==0)
    {
        return 0;
    }
    if(i==1)
    {
        return 1;
    }
    return (fib(i-1)+fib(i-2));
}