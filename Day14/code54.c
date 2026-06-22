#include <stdio.h>
int main() 
{
    int size,i,item,count = 0;

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    int arr[size]; 

    printf("Enter %d Elements:\n",size);
    for (i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the Element to Find its Frequency:");
    scanf("%d",&item);

    for (i = 0;i < size;i++) 
    {
        if (arr[i] == item) 
        {
            count++;
        }
    }

    if (count > 0) 
    {
        printf("The Element %d Occurs %d Times in the Array\n",item,count);
    } 
    else 
    {
        printf("Element %d is not Present in the Array.\n",item);
    }

    return 0;
}