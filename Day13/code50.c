#include <stdio.h>
int main()
{
    int size, i;
    int sum = 0;
    float average;

    printf("Enter the Number of Elements:");
    scanf("%d",&size);

    int arr[size]; 

    printf("Enter the Elements of the Array:\n");
    for (i = 0;i < size;i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    average = (float)sum / size;

    printf("\nThe Sum of the Array Elements is = %d",sum);
    printf("\nThe Average of the Array Elements is = %.2f\n",average);

    return 0;
}