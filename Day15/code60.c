#include <stdio.h>
int main() 
{
    int size,i,count = 0; 

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    int arr[size];

    printf("Enter %d Elements:\n",size);
    for (i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }
    for (i = 0;i < size;i++) 
    {
        if (arr[i] != 0) 
        {
            arr[count] = arr[i];
            count++;
        }
    }

    while (count < size) 
    {
        arr[count] = 0;
        count++;
    }

    printf("Array After Moving Zeroes to End:\n");
    for (i = 0; i < size; i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}