#include<stdio.h>
int factorial(int);
int main()
{
    int n,Result;
    printf("Enter the Number:");
    scanf("%d",&n);

    Result=factorial(n);
    printf("The Factorial is = %d\n",Result);
    return 0;
}
int factorial(int n)
{
    if(n==0)
    {
        return (1);
    }
    else
    {
        return (n*factorial(n-1));
    }
}