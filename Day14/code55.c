#include <stdio.h>
int main() 
{
    int size,i,max1,max2;

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    if (size < 2) 
    {
        printf("Invalid Size!\n");
        return 0;
    }

    int arr[size]; 

    printf("Enter %d Elements:\n",size);
    for (i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    max1 = arr[0];
    max2 = -1;

    for (i = 1;i < size;i++) 
    {
        if (arr[i] > max1) 
        {
            max2 = max1;
            max1 = arr[i];
        } 
        else if (arr[i] < max1 && (max2 == -1 || arr[i] > max2)) 
        {
            max2 = arr[i];
        }
    }

    if (max2 == -1 || max1 == max2) 
    {
        printf("There is no Distinct Second Largest Element\n");
    } 
    else 
    {
        printf("Largest: %d, Second Largest: %d\n",max1,max2);
    }

    return 0;
}