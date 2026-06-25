#include <stdio.h>

int main() 
{
    int size1,size2,i,j,k,m,flag;

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

    int intersect[size1]; 
    k = 0;

    for (i = 0;i < size1;i++) 
    {
        for (j = 0;j < size2;j++) 
        {
            if (arr1[i] == arr2[j]) 
            {
                flag = 0;
                for (m = 0;m < k;m++) 
                {
                    if (arr1[i] == intersect[m]) 
                    {
                        flag = 1;
                        break;
                    }
                }

                if (!flag) 
                {
                    intersect[k] = arr1[i];
                    k++;
                }
                break;
            }
        }
    }

    if (k == 0) 
    {
        printf("\nThe Intersection of the Two Arrays is Empty\n");
    } 
    else 
    {
        printf("\nThe Intersection of the Two Arrays is:\n");
        for (i = 0;i < k;i++) 
        {
            printf("%d ",intersect[i]);
        }
        printf("\n");
    }

    return 0;
}