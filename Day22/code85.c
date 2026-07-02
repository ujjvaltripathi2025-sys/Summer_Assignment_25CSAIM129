#include <stdio.h>
#include <string.h>
int main() 
{
    char str[100];
    int i,len;
    int palindrome = 1;

    printf("Enter a String: ");
    scanf("%s",str);

    len = strlen(str);

    for (i = 0;i < len / 2;i++) 
    {
        if (str[i] != str[len - 1 - i]) 
        {
            palindrome = 0;
            break;
        }
    }

    if (palindrome) 
    {
        printf("\"%s\" is a Palindrome String\n",str);
    } 
    else 
    {
        printf("\"%s\" is Not a Palindrome String\n",str);
    }

    return 0;
}