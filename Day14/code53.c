#include <stdio.h>
int main() 
{
    int size,i,item,found = 0;

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    int arr[size]; 

    printf("Enter %d Elements:\n",size);
    for (i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the Element to search:");
    scanf("%d",&item);

    for (i = 0;i < size;i++) 
    {
        if (arr[i] == item) 
        {
            printf("Element Found at Index: %d\n",i);
            found = 1;
            break;
        }
    }

    if (found == 0) 
    {
        printf("Element is not Present in the Array\n");
    }

    return 0;
}