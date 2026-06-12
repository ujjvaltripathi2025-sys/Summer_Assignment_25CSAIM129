#include<stdio.h>
int main()
{
    int n,d,temp,Rev=0;
    printf("Enter the Number:");
    scanf("%d",&n);
    temp=n;

    while(n>0)
    {
        d=n%10;
        Rev=Rev*10+d;
        n=n/10;
    }
    if(Rev==temp)
    {
        printf("The Number is Palindrome:");
    }
    else
    {
        printf("The Number is not Palindrome");
    }
    return 0;
}