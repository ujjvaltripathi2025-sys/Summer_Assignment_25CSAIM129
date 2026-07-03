#include <stdio.h>
#include <string.h>
int duplicates(char [],char []);
int main()
{
    char s1[100];
    char s2[100];
    
    printf("Enter a String:");
    scanf("%s",s1);
    
    duplicates(s1,s2);
    
    printf("String After Removing Duplicates: %s\n",s2);
    
    return 0;
}

int duplicates(char str[],char result[])
{
    int len = strlen(str);
    int count[256] = {0};
    int j = 0;
    int i;
    
    for (i = 0;i < len;i++)
    {
        int value = (int)str[i];
        
        if (count[value] == 0)
        {
            count[value] = 1;
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    
    return j;
}