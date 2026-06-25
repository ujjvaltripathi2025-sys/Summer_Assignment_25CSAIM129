#include <stdio.h>
int main() 
{
    int size1,size2,i,j;

    printf("Enter the Size of the First Array:");
    scanf("%d",&size1);
    
    int arr1[size1];
    printf("Enter %d Elements for the First Array:\n",size1);
    for (i = 0;i < size1;i++) 
    {
        scanf("%d",&arr1[i]);
    }

    printf("\nEnter the Size of the Second Array:");
    scanf("%d",&size2);
    
    int arr2[size2];
    printf("Enter %d Elements for the Second Array:\n",size2);
    for (i = 0;i < size2;i++) 
    {
        scanf("%d",&arr2[i]);
    }

    int merged[size1 + size2];

    for (i = 0;i < size1;i++) 
    {
        merged[i] = arr1[i];
    }

    for (j = 0;j < size2;j++) 
    {
        merged[size1 + j] = arr2[j];
    }

    printf("\nThe Merged Array Elements are:\n");
    for (i = 0;i < (size1 + size2);i++) 
    {
        printf("%d ",merged[i]);
    }
    printf("\n");

    return 0;
}