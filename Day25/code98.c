#include <stdio.h>
#include <string.h>
int main() 
{
    char str1[100],str2[100];
    int i,j,k;
    int f;

    printf("Enter first string: ");
    scanf("%s",str1);

    printf("Enter second string: ");
    scanf("%s",str2);

    printf("Common characters are: ");

    for (i = 0;str1[i] != '\0';i++) 
    {
        f = 0;
        
        for (k = 0;k < i;k++) 
        {
            if (str1[i] == str1[k]) 
            {
                f = 1;
            }
        }

        if (f == 0) 
        {
            for (j = 0;str2[j] != '\0';j++) 
            {
                if (str1[i] == str2[j]) 
                {
                    printf("%c ",str1[i]);
                    break;
                }
            }
        }
    }
    printf("\n");

    return 0;
}