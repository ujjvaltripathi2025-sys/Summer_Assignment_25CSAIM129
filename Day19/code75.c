#include <stdio.h>
int main()
{
    int i,j;

    int a[3][3],trans[3][3];

    printf("Enter Elements of Matrix :\n");
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            printf("Enter Element a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            trans[j][i] = a[i][j];
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

    printf("\nTranspose of the Matrix is:\n");
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            printf("%d\t",trans[i][j]); 
        }
        printf("\n");
    }

    return 0;
}