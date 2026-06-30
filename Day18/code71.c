#include <stdio.h>
int main() 
{
    int size,i,item,low,high,mid,flag = 0;

    printf("Enter the Size of Array:");
    scanf("%d",&size);

    int arr[size]; 

    printf("Enter %d Elements in Sorted Order:\n",size);
    for (i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the Element to Search:");
    scanf("%d",&item);

    low = 0;
    high = size - 1;

    while (low <= high) 
    {
        mid = (low + high) / 2;

        if (arr[mid] == item) 
        {
            printf("Element Found at Position %d\n",mid + 1);
            flag = 1;
            break;
        }
        else if (arr[mid] < item) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
        if (flag == 0)
        {
            printf("Element not Found in the Array\n");
        }
    }
    return 0;
}