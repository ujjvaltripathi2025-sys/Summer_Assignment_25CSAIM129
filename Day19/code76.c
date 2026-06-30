#include <stdio.h>
int main()
{
    int i,j;
    int a[3][3],sum = 0;

    printf("Enter Elements of Matrix:\n");
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            printf("Enter Element a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nOriginal Matrix is:\n");
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            if (i == j)
            {
                sum = sum + a[i][j];
            }
        }
    }

    printf("\nThe Sum of Diagonal Elements is = %d\n",sum);

    return 0;
}