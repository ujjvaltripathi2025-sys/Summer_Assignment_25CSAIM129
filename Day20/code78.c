#include <stdio.h>
int main() 
{
    int i, j;
    int symmetric = 1; 
    int a[3][3];

    printf("Enter Elements of Matrix a :\n");
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
            if (a[i][j] != a[j][i]) 
            {
                symmetric = 0;
            }
        }
    }

    if (symmetric == 1) 
    {
        printf("\nThe Given Matrix is a Symmetric Matrix\n");
    }
    else 
    {
        printf("\nThe Given Matrix is NOT a Symmetric Matrix\n");
    }

    return 0;
}