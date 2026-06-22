#include <stdio.h>
#define size 100
int main() 
{
    int Size,i;

    printf("Enter the Number of Elements:");
    scanf("%d",&Size);

    int arr[Size];
    printf("Enter %d Elements:\n", Size);
    for(i = 0;i < Size;i++) 
    {
        scanf("%d",&arr[i]);
    }

    printf("\nThe Elements in the Array are:\n");
    for(i = 0;i < Size;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}