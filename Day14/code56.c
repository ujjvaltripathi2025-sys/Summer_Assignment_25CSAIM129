#include <stdio.h>
int main() 
{
    int size,i,j,temp;

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    int arr[size]; 

    printf("Enter %d Elements:\n",size);
    for (i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    for (i = 0;i < size - 1;i++) 
    {
        for (j = 0;j < size - i - 1;j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nDuplicate Elements Found:\n");

    for (i = 0;i < size - 1;i++) 
    {
        if (arr[i] == arr[i + 1]) 
        {
            printf("%d\n",arr[i]);

            while (i < size - 1 && arr[i] == arr[i + 1]) 
            {
                i++;
            }
        }
    }

    return 0;
}