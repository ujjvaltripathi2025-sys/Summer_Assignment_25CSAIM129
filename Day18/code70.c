#include <stdio.h>
int main() 
{
    int size,i,j,temp,min;

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
        min = i;
        for (j = i + 1;j < size;j++) 
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        }

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    printf("The Sorted Array is:\n");
    for (i = 0;i < size;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}