#include <stdio.h>
int main() 
{
    char str[200];
    int i = 0;
    int words = 0;
    int word = 0;

    printf("Enter a Sentence: ");
    scanf("%[^\n]",str);

    while (str[i] != '\0') 
    {
        if (str[i] == ' ' || str[i] == '\t') 
        {
            word = 0;
        } 
        
        if (str[i] != ' ' && str[i] != '\t' && word == 0) 
        {
            word = 1;
            words++;
        }
        
        i++;
    }

    printf("Total Number of Words: %d\n",words);

    return 0;
}