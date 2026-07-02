#include <stdio.h>
int main() 
{
    char str[200];
    int i = 0;
    int freq[256] = {0};

    printf("Enter a String: ");
    scanf("%[^\n]",str);

    while (str[i] != '\0') 
    {
        freq[(unsigned char)str[i]]++;
        i++;
    }

    for (i = 0;i < 256;i++) 
    {
        if (freq[i] != 0) 
        {
            printf("Character '%c' occurs %d times\n", i, freq[i]);
        }
    }

    return 0;
}