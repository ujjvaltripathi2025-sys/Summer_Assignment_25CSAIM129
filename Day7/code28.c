#include<stdio.h>
int Reverse(int,int);
int main()
{
    int n,Result;
    printf("Enter the Number:");
    scanf("%d",&n);

    Result=Reverse(n,0);
    printf("The Reverse Number is = %d\n",Result);
    return 0;
}
int Reverse(int n,int rev)
{
    if(n==0)
    {
        return rev;
    }
    else
    {
        return Reverse(n/10,rev*10+n%10);
    }
}