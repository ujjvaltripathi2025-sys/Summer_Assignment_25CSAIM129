#include <stdio.h>
#include <string.h>
int main() 
{
    char words[100][100];
    char temp[100];
    int n,i,j;

    printf("Enter number of words: ");
    scanf("%d",&n);

    printf("Enter words in any order:\n");
    for (i = 0;i < n;i++) 
    {
        scanf("%s",words[i]);
    }

    for (i = 0;i < n;i++) 
    {
        for (j = i + 1;j < n;j++) 
        {
            if (strlen(words[i]) > strlen(words[j])) 
            {
                strcpy(temp,words[i]);
                strcpy(words[i],words[j]);
                strcpy(words[j],temp);
            }
        }
    }

    printf("\nThe sorted words by length are:\n");
    for (i = 0;i < n;i++) 
    {
        printf("%s\n",words[i]);
    }

    return 0;
}