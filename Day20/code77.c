#include <stdio.h>
int main() 
{
    int i, j, k;
    int a[3][3];
    int b[3][2];
    int result[3][2];

    printf("Enter Elements of Matrix a :\n");
    for (i = 0;i < 3;i++) 
    {
        for (j = 0;j < 3;j++) 
        {
            printf("Enter Element a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nEnter Elements of Matrix b :\n");
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            printf("Enter Element b[%d][%d]: ",i,j);
            scanf("%d",&b[i][j]);
        }
    }

    for (i = 0;i < 3;i++) 
    {
        for (j = 0;j < 2;j++)
        {
            result[i][j] = 0;
            for (k = 0;k < 3;k++)
            {
                result[i][j] = result[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }

    printf("\nResultant Multiplied Matrix :\n");
    for (i = 0;i < 3;i++) 
    {
        for (j = 0;j < 2;j++) 
        {
            printf("%d\t",result[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}