#include <stdio.h>
int Armstrong(int);

int main()
{
    int n;
    printf("Enter the Number:");
    scanf("%d",&n);

    if (Armstrong(n) == 1)
    {
        printf("%d is an Armstrong Number\n",n);
    }
    else
    {
        printf("%d is not an Armstrong Number\n",n);
    }

    return 0;
}

int Armstrong(int n)
{
    int original = n;
    int temp = n;
    int d, sum = 0, count = 0;

    while (temp > 0)
    {
        count++;
        temp = temp / 10;
    }

    while (n > 0)
    {
        d = n % 10;
        int p = 1;
        for (int i = 0; i < count; i++)
        {
            p = p * d;
        }
        
        sum = sum + p;
        n = n / 10;
    }

    if (original == sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}