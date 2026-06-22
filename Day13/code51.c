#include <stdio.h>
int main()
{
    int size,i;
    int largest,smallest;

    printf("Enter the Number of Elements:");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the Elements of the Array:\n");
    for (i = 0;i < size;i++)
    {
        scanf("%d",&arr[i]);
    }

    largest = arr[0];
    smallest = arr[0];

    for (i = 1;i < size;i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }

        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    printf("\nThe Largest Element in the Array is = %d",largest);
    printf("\nThe Smallest Element in the Array is = %d\n",smallest);

    return 0;
}