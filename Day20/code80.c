#include <stdio.h>
int main() 
{
    int i, j;
    int sum;
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

    printf("\nColumn-wise Sum Results:\n");
    for (j = 0;j < 3;j++)
    {
        sum = 0;
        for (i = 0;i < 3;i++)
        {
            sum = sum + a[i][j]; 
        }
        printf("Sum of Elements in Column %d = %d\n",j + 1,sum);
    }

    return 0;
}