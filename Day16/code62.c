#include <stdio.h>
int main() 
{
    int size, i, j;
    int count, max = 0, element;

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    int arr[size]; 

    printf("Enter Elements:");
    for(i = 0;i < size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    for(i = 0;i < size;i++) 
    {
        count = 0; 
        
        for(j = 0;j < size;j++) 
        {
            if(arr[i] == arr[j]) 
            {
                count++;
            }
        }
        
        if(count > max) 
        {
            max = count;
            element = arr[i];
        }
    }

    printf("Most Frequent Element: %d\n",element);

    return 0;
}