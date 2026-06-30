#include <stdio.h>

int main() 
{
    int size,i,j,temp;

    printf("Enter the Size of Array:");
    scanf("%d",&size);

    int arr[size]; 

    printf("Enter %d Elements:\n",size);
    for (i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    for (i = 0;i < size - 1;i++) 
    {
        for (j = 0;j < size - 1 - i;j++) 
        {
            if (arr[j] < arr[j + 1]) 
            { 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("The Sorted Array in Descending Order is:\n");
    for (i = 0;i < size;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}