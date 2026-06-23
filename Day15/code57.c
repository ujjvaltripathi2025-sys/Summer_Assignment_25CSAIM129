#include <stdio.h>
int main() 
{
    int size,temp,i;

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    int arr[size];

    printf("Enter %d Elements:\n",size);
    for (i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    for (i = 0;i < size / 2;i++) 
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }

    printf("Reversed Array:\n");
    for (int i = 0;i < size;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}