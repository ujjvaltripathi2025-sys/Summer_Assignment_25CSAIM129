#include <stdio.h>
int Perfect(int);

int main()
{
    int n;
    printf("Enter the Number:");
    scanf("%d",&n);

    if (Perfect(n) == 1)
    {
        printf("%d is a Perfect Number\n",n);
    }
    else
    {
        printf("%d is not a Perfect Number\n",n);
    }

    return 0;
}

int Perfect(int n)
{
    int sum = 0;
    int i;

    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }

    if (sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}