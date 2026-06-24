#include <stdio.h>
int main() 
{
    int size,i;
    int sum1,sum2 = 0,missing;

    printf("Enter the Size of the Array:");
    scanf("%d",&size);

    int arr[size - 1]; 

    printf("Enter Elements:");
    for(i = 0;i < size - 1;i++) 
    {
        scanf("%d",&arr[i]);
    }

    sum1 = (size * (size + 1)) / 2;

    for(i = 0;i < size - 1;i++) 
    {
        sum2 = sum2 + arr[i];
    }

    missing = sum1 - sum2;

    printf("The Missing Number is: %d\n",missing);

    return 0;
}