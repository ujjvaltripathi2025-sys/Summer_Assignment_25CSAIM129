#include <stdio.h>
int Palindrome(int);

int main()
{
    int n;
    printf("Enter the Number: ");
    scanf("%d",&n);

    if (Palindrome(n) == 1)
    {
        printf("%d is a Palindrome Number\n",n);
    }
    else
    {
        printf("%d is not a Palindrome Number\n",n);
    }

    return 0;
}

int Palindrome(int n)
{
    int original = n;
    int d,rev = 0;

    while (n > 0)
    {
        d = n % 10;
        rev = rev * 10 + d;
        n = n / 10;
    }

    if (original == rev)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}