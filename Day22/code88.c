#include <stdio.h>

int main() 
{
    char str[200];
    int i = 0;
    int j = 0;

    printf("Enter a String: ");
    scanf("%[^\n]",str);

    while (str[i] != '\0') 
    {
        if (str[i] != ' ' && str[i] != '\t') 
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    
    str[j] = '\0';

    printf("String After Removing Spaces: %s\n",str);

    return 0;
}