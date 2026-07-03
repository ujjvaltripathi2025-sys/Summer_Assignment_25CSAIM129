#include <stdio.h>
int main() 
{
    int a[50],b[50],c[100];
    int n1,n2,i,j,k;

    printf("Enter number of elements in first array: ");
    scanf("%d",&n1);
    printf("Enter sorted elements for first array:\n");
    for (i = 0;i < n1;i++) 
    {
        scanf("%d",&a[i]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);
    printf("Enter sorted elements for second array:\n");
    for (j = 0;j < n2;j++) 
    {
        scanf("%d",&b[j]);
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2) 
    {
        if (a[i] < b[j]) 
        {
            c[k] = a[i];
            i++;
        }
        else 
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        c[k] = b[j];
        j++;
        k++;
    }
 
    printf("\nThe merged sorted array is:\n");
    for (i = 0; i < k; i++) 
    {
        printf("%d ",c[i]);
    }
    printf("\n");

    return 0;
}