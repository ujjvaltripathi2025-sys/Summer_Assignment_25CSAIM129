#include <stdio.h>
int main() 
{
    int size1, size2, i, j, k;
    int Duplicate;

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

    int uni[size1 + size2];
    k = 0;

    for (i = 0;i < size1;i++) 
    {
        Duplicate = 0;
        for (j = 0;j < k;j++) 
        {
            if (arr1[i] == uni[j]) 
            {
                Duplicate = 1;
                break;
            }
        }
        if (!Duplicate) 
        {
            uni[k] = arr1[i];
            k++;
        }
    }

    for (i = 0;i < size2;i++) 
    {
        Duplicate = 0;
        for (j = 0;j < k;j++) 
        {
            if (arr2[i] == uni[j]) 
            {
                Duplicate = 1;
                break;
            }
        }
        if (!Duplicate) 
        {
            uni[k] = arr2[i];
            k++;
        }
    }

    printf("\nThe Union of the Two Arrays is:\n");
    for (i = 0;i < k;i++) 
    {
        printf("%d ",uni[i]);
    }
    printf("\n");

    return 0;
}