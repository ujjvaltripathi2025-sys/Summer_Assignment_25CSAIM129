#include <stdio.h>
#include <string.h>
int main() 
{
    char names[30][30];
    char temp[30];
    int n,i,j;

    printf("Enter number of names: ");
    scanf("%d",&n);

    printf("Enter names in any order:\n");
    for (i = 0;i < n;i++) 
    {
        scanf("%s",names[i]);
    }

    for (i = 0;i < n;i++) 
    {
        for (j = i + 1;j < n;j++) 
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                strcpy(temp,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],temp);
            }
        }
    }

    printf("\nThe sorted alphabetical order of names is:\n");
    for (i = 0;i < n;i++) {
        printf("%s\n",names[i]);
    }

    return 0;
}