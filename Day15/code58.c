#include <stdio.h>
int main() 
{
    int size,d,i;

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    int arr[size];

    printf("Enter %d Elements:\n",size);
    for (i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter Number of Positions to Rotate Left:");
    scanf("%d",&d);

    d = d % size;

    int temp[d];

    for (i = 0;i < d;i++) 
    {
        temp[i] = arr[i];
    }

    for (i = d;i < size;i++) 
    {
        arr[i - d] = arr[i];
    }

    for (i = 0;i < d;i++) 
    {
        arr[size - d + i] = temp[i];
    }

    printf("Array After Left Rotation:\n");
    for (i = 0;i < size;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}