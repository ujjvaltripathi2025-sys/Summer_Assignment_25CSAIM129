#include <stdio.h>
int main()
{
    int i, j;
    
    int a[3][3],b[3][3],diff[3][3];

    printf("Enter Elements of 1st Matrix :\n");
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            printf("Enter Element a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nEnter Elements of 2nd Matrix :\n");
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            printf("Enter Element b[%d][%d]: ",i,j);
            scanf("%d",&b[i][j]);
        }
    }

    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            diff[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("\nSubtraction of the Two Matrices is:\n");
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            printf("%d\t",diff[i][j]);
        }
        printf("\n");
    }
    return 0;
}