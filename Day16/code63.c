#include <stdio.h>
int main() 
{
    int size,i,j;
    int target,found = 0;

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    int arr[size]; 

    printf("Enter Elements:");
    for(i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter Target Sum:");
    scanf("%d",&target);

    for(i = 0;i < size;i++) 
    {
        for(j = i + 1;j < size;j++) 
        {
            if(arr[i] + arr[j] == target) 
            {
                printf("Pair Found: %d and %d\n",arr[i],arr[j]);
                found = 1;
            }
        }
    }

    if(found == 0) 
    {
        printf("No Pair Found with the Given Sum\n");
    }

    return 0;
}