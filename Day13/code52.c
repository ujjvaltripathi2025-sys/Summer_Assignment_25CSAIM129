#include <stdio.h>
int main()
{
    int size,i;
    int even = 0;
    int odd = 0;

    printf("Enter the Number of Elements:");
    scanf("%d",&size);

    int arr[size];

    printf("Enter the Elements of the Array:\n");
    for (i = 0;i < size;i++)
    {
        scanf("%d",&arr[i]);

        if (arr[i] % 2 == 0)
        {
            even = even + 1;
        }
        else
        {
            odd = odd + 1;
        }
    }

    printf("\nTotal Even Elements = %d",even);
    printf("\nTotal Odd Elements = %d\n",odd);

    return 0;
}