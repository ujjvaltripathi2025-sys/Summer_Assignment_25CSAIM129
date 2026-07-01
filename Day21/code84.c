#include <stdio.h>
int main() 
{
    char str[100];
    int i = 0;

    printf("Enter a String: ");
    scanf("%[^\n]",str);

    while (str[i] != '\0') 
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            str[i] = str[i] - 32;
        }
        i++;
    }

    printf("Uppercase String: %s\n",str);

    return 0;
}